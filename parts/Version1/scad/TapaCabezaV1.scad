difference(){
	translate([-9,-25.5,0])cube([15,51,3]);
	union(){
		translate([0,-23.25,0])cylinder(r=3/2,h=10, $fn=10);
		translate([0,23.25,0])cylinder(r=3/2,h=10, $fn=10);
	}
	translate([-7,-21.5,1])cube([11,43,3]);
}