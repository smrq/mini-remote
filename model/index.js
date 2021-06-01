const fs = require('fs');
const { compile, globals } = require('@smrq/openscad-js');

with (globals(x => eval(x))) {
	const eps = 0.001;

	function flatten(arr) {
		return [].concat(...arr);
	}

	function cube2(size, { center: [centerX, centerY, centerZ], ...options }) {
		const [x,y,z] = Array.isArray(size) ? size : [size, size, size];
		return translate([
			centerX ? -x/2 : 0,
			centerY ? -y/2 : 0,
			centerZ ? -z/2 : 0,
		])(
			cube(size, options)
		);
	}

	const pcbSize = { x: 45.5, y: 98, z: 1.6 };
	const pcbMargin = 0.5;
	const wallThickness = 1.5;
	const overhangThickness = 1.5;

	const innerSizePcbEdge = {
		x: pcbSize.x + 2*pcbMargin,
		y: pcbSize.y + 2*pcbMargin,
	};

	const innerSizeMidWall = {
		x: innerSizePcbEdge.x + 2*overhangThickness,
		y: innerSizePcbEdge.y + 2*overhangThickness,
	};

	const topY = -56;
	const bottomY = 56 + 15;
	const outerSize = {
		x: innerSizeMidWall.x + 2*wallThickness,
		y: bottomY - topY,
	};

	const topOuterZ = 5;
	const topInnerZ = 3;
	const pcbTopZ = 0;
	const pcbBottomZ = -1.6;
	const ledCenterZ = -4.8;
	const overhangZ = 0;
	const bottomInnerZ = -8;
	const bottomOuterZ = -10;

	const buttonPositions = [
		[[-15,    15], -44.25],
		[[-15, 0, 15], -30.75],
		[[-7,      7],  -9.75],
		[[-15, 0, 15],   3.75],
		[[-15, 0, 15],  17.25],
		[[-15, 0, 15],  30.75],
		[[-15, 0, 15],  44.25],
	];
	const screwPositions = [
		[0, -3],
		[-18, -37.5],
		[ 18, -37.5],
		[-18,  37.5],
		[ 18,  37.5],
	];
	const ledCutoutRadius = 3.2;

	const topModel = difference()(
		union()(
			difference()(
				translate([0, topY, overhangZ])(
					cube2([outerSize.x, bottomY - topY, topOuterZ - overhangZ], { center: [true, false, false] })
				),
				translate([0, 0, overhangZ - eps])(
					cube2([innerSizeMidWall.x, innerSizeMidWall.y, topInnerZ - overhangZ + eps], { center: [true, true, false] })
				),
			),
			...screwPositions.map(([x, y]) => (
				translate([x, y, pcbTopZ])(
					cylinder({ r: 3, h: topInnerZ - pcbTopZ })
				)
			))
		),
		...flatten(buttonPositions.map(([xs, y]) => xs.map(x => (
			translate([x, y, topInnerZ - eps])(
				minkowski()(
					cube2([6, 6, topOuterZ - topInnerZ + eps], { center: [true, true, false] }),
					cylinder({ r: 0.25, h: eps })
				)
			)
		)))),
		translate([0, -46.25, topInnerZ - eps])(
			minkowski()(
				cube2([3.2, 2, topOuterZ - topInnerZ + eps], { center: [true, true, false] }),
				cylinder({ r: 0.25, h: eps })
			)
		),
		...screwPositions.map(([x, y]) => (
			union()(
				translate([x, y, topOuterZ - 1.4])(
					cylinder({ r: 1.75, h: 1.4 + eps })
				),
				translate([x, y, pcbTopZ - eps])(
					cylinder({ r: 1.1, h: topOuterZ - pcbTopZ + 2*eps })	
				),
			)
		))
	);

	const bottomModel = difference()(
		union()(
			difference()(
				union()(
					translate([0, topY, bottomOuterZ])(
						cube2([outerSize.x, bottomY - topY, overhangZ - bottomOuterZ], { center: [true, false, false] })
					),
					translate([0, 0, overhangZ])(
						cube2([innerSizeMidWall.x, innerSizeMidWall.y, topInnerZ - overhangZ], { center: [true, true, false] })
					),
				),
				translate([0, 0, bottomInnerZ])(
					cube2([innerSizePcbEdge.x, innerSizePcbEdge.y, topInnerZ - bottomInnerZ + eps], { center: [true, true, false] })
				),
			),
			...screwPositions.map(([x, y]) => (
				translate([x, y, bottomInnerZ])(
					cylinder({ r: 3, h: pcbBottomZ - bottomInnerZ })
				)
			))
		),
		translate([0, topY + 15, ledCenterZ])(
			rotate([90, 0, 0])(
				cylinder({ r: ledCutoutRadius, h: 30 })
			)
		),
		...screwPositions.map(([x, y]) => (
			union()(
				translate([x, y, bottomOuterZ - eps])(
					cylinder({ r: 2.25, h: 1.5 + eps, $fn: 6 })
				),
				translate([x, y, bottomOuterZ - eps])(
					cylinder({ r: 1.1, h: pcbBottomZ - bottomOuterZ + 2*eps })
				),
			)
		))
	)

	const preview = union()(
		translate([0, 0, 20])(topModel),
		bottomModel,
	);

	const header = '$fn = 100;\n';

	fs.writeFileSync('top.scad', header + compile(topModel), 'utf8');
	fs.writeFileSync('bottom.scad', header + compile(bottomModel), 'utf8');
	fs.writeFileSync('preview.scad', header + compile(bottomModel), 'utf8');
}
