import cadquery as cq

# Case specs
(case_size_x, case_size_y) = (55, 130)
case_thickness = 2
top_thickness = 1
fudge = 0.25

top_fillet = 0.5
side_fillet = 4
bottom_fillet = 8

# PCB specs
# Positions are centered on the center point of the PCB
(pcb_size_x, pcb_size_y, pcb_size_z) = (45.5, 98, 1.6)
screw_positions = [
	# (0, 3),
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
irled_clearance = 7

screw_radius = 1.35
screw_counterbore_radius = 2
screw_post_radius = 3
screw_counterbore_depth = 1.4

threaded_insert_radius = 1.5
threaded_insert_countersink_radius = 2.2
threaded_insert_post_radius = 3.95

# Calculated specs
outer_depth_top = button_height
inner_depth_top = outer_depth_top - top_thickness
inner_depth_bottom = pcb_size_z + 2*irled_radius

pcb_center = (0, case_size_y/2 - irled_clearance - pcb_size_y/2)

lip_height = inner_depth_top
screw_post_height = inner_depth_top
threaded_insert_post_height = inner_depth_bottom - pcb_size_z

# Model definitions

case_top = (
	cq.Workplane("XY")

	# Define shape
	.rect(case_size_x, case_size_y)
	.extrude(top_thickness)
	
	.faces("<X or >X")
	.edges("|Z")
	.fillet(side_fillet)

	# Extrude seam lip
	.faces("<Z")
	.tag("unextruded_seam_face")
	.wires(cq.selectors.AreaNthSelector(-1))
	.toPending()
	.offset2D(-case_thickness + fudge)
	.wires(cq.selectors.AreaNthSelector(0), tag="unextruded_seam_face")
	.toPending()
	.workplane()
	.extrude(-lip_height)

	.faces("<Z")
	.tag("seam_face")
	.end()

	# Screw posts
	.faces(">Z")
	.workplane()
	.center(pcb_center[0], pcb_center[1])
	.pushPoints(screw_positions)
	.circle(screw_post_radius)
	.extrude(-outer_depth_top)

	.faces(">Z")
	.workplane()
	.pushPoints(screw_positions)
	.cboreHole(screw_radius*2, screw_counterbore_radius*2, screw_counterbore_depth)

	# Fillet top edges and screw holes
	.edges(">Z")
	.fillet(top_fillet)

	# Buttons
	.pushPoints(button_positions)
	.rect(button_size, button_size)
	.cutThruAll()

	# Status LED
	.pushPoints([statusled_position])
	.rect(statusled_size[0], statusled_size[1])
	.cutThruAll()
)

case_bottom = (
	cq.Workplane("XY")

	# Define shape
	.rect(case_size_x, case_size_y)
	.extrude(case_thickness)

	.faces(">Z")
	.rect(case_size_x, case_size_y)
	.rect(case_size_x-4*case_thickness, case_size_y-4*case_thickness)
	.extrude(inner_depth_bottom)
	
	.faces("<Z")
	.edges()
	.fillet(bottom_fillet)

	.faces("<Z[-2]")
	.edges()
	.fillet(bottom_fillet - case_thickness)

	.faces("<X or >X")
	.edges("|Z")
	.fillet(side_fillet)
	
	# Extrude seam lip
	.faces(">Z")
	.tag("unextruded_seam_face")
	.wires(cq.selectors.AreaNthSelector(-1))
	.toPending()
	.offset2D(-case_thickness - fudge)
	.wires(cq.selectors.AreaNthSelector(0), tag="unextruded_seam_face")
	.toPending()
	.workplane()
	.extrude(lip_height)

	.faces(">Z[-2]")
	.tag("seam_face")
	.end()

	# Threaded insert posts
	.faces("<Z[-2]")
	.workplane()
	.center(pcb_center[0], pcb_center[1])
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
	.cutBlind(-case_thickness*2 - (bottom_fillet - case_thickness)) # cut through surface and fillet
)

assembled = (
	cq.Assembly()
	.add(case_top, name="case_top", color=cq.Color(0,1,1,0.25))
	.add(case_bottom, name="case_bottom", color=cq.Color(1,0,0,1))
	.constrain("case_bottom?seam_face", "case_top?seam_face", "Plane")
)
assembled.solve()

show_object(assembled)
# show_object(case_top, options={"alpha":0.1}, name="case_top")
# show_object(case_bottom, name="case_bottom")
