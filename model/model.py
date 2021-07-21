import cadquery as cq

# Case specs
case_thickness = 2
pcb_margin = 4
extra_height = 25
lip_height = 1
fudge = 0.1

side_fillet = 2
bottom_fillet = 6

# PCB specs
(pcb_size_x, pcb_size_y, pcb_size_z) = (45.5, 98, 1.6)
screw_positions = [
	(0, 3),
	(-18, -37.5),
	( 18, -37.5),
	(-18,  37.5),
	( 18,  37.5)
]
button_positions = [
	(-15, 44.25),             (15, 44.25),
	(-15, 30.75), (0, 30.75), (15, 30.75),
	(-7.5, 9.75),              (8,  9.75),
	(-15, -3.75), (0, -3.75), (15, -3.75),
	(-15,-17.25), (0,-17.25), (15,-17.25),
	(-15,-30.75), (0,-30.75), (15,-30.75),
	(-15,-44.25), (0,-44.25), (15,-44.25),
]

# Component specs
button_height = 3.7
button_size = 7.25

statusled_size = (4, 2.75)
statusled_position = (0, 46.25)

irled_radius = 3.2

screw_radius = 1.35
screw_counterbore_radius = 2
screw_post_radius = 3
screw_counterbore_depth = 1.4

threaded_insert_radius = 1.8
threaded_insert_countersink_radius = 2.3
threaded_insert_post_radius = 3.95

# Calculated specs
inner_width = pcb_size_x + pcb_margin
inner_height = pcb_size_y + pcb_margin + extra_height
inner_depth_top = button_height - case_thickness
inner_depth_bottom = pcb_size_z + 2*irled_radius

screw_post_height = inner_depth_top
threaded_insert_post_height = inner_depth_bottom - pcb_size_z

# Model definitions

case_bottom = (
	cq.Workplane("XY")

	# Define interior shape
	.rect(inner_width, inner_height)
	.extrude(inner_depth_bottom)
	
	# Fillet edges
	.edges("|Z")
	.fillet(side_fillet)
	.edges("<Z")
	.fillet(bottom_fillet)

	# Extrude shell containing interior shape
	.faces(">Z")
	.shell(case_thickness)
	
	# Extrude seam lip
	.faces(">Z")
	.tag("seam_face")
	.wires(cq.selectors.AreaNthSelector(-1))
	.toPending()
	.offset2D(-case_thickness/2 - fudge)
	.wires(cq.selectors.AreaNthSelector(0), tag="seam_face")
	.toPending()
	.workplane()
	.extrude(lip_height - fudge)

	# Threaded insert posts
	.faces("<Z[-2]")
	.workplane()
	.tag("inner_base_plane")
	.center(0, extra_height/2)
	.pushPoints(screw_positions)
	.circle(threaded_insert_post_radius)
	.extrude(threaded_insert_post_height)
	.faces("<Z[-3]")
	.cskHole(threaded_insert_radius*2, threaded_insert_countersink_radius*2, 45, threaded_insert_post_height)

	# IR LED cutout
	.faces(">Y")
	.workplane()
	.center(0,irled_radius)
	.circle(irled_radius)
	.cutBlind(-case_thickness*10) # cut to surface is not supported, so just do a huge cut instead
)

case_top = (
	cq.Workplane("XY")
	.center(60,0)

	# Define interior shape
	.rect(inner_width, inner_height)
	.extrude(inner_depth_top)
	
	# Fillet edges
	.edges("|Z")
	.fillet(side_fillet)

	# Extrude shell containing interior shape
	.faces("<Z")
	.shell(case_thickness)	

	# Cut out seam lip
	.faces("<Z")
	.wires(cq.selectors.AreaNthSelector(-1))
	.toPending()
	.offset2D(-case_thickness/2 + fudge)
	.workplane()
	.cutBlind(lip_height + fudge)

	# Buttons
	.faces(">Z")
	.center(0, extra_height/2)
	.pushPoints(button_positions)
	.rect(button_size, button_size)
	.cutThruAll()

	# Status LED
	.pushPoints([statusled_position])
	.rect(statusled_size[0], statusled_size[1])
	.cutThruAll()

	# Screw posts
	.faces(">Z[-2]")
	.pushPoints(screw_positions)
	.circle(screw_post_radius)
	.extrude(screw_post_height)
	.faces(">Z")
	.workplane()
	.pushPoints(screw_positions)
	.cboreHole(screw_radius*2, screw_counterbore_radius*2, screw_counterbore_depth)
)

case_top = case_top.rotateAboutCenter((0,1,0), 180)

show_object(case_bottom, name="case_bottom")
show_object(case_top, name="case_top")
