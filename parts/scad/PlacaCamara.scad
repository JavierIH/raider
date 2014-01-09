difference(){
	union(){
		translate([-35/2,0,0])cube([35,31,4]);
		translate([-35/2,0,0])cube([35,5,10]);
	}		
	translate([-19/2,-2,0.5])cube([19,40,6]);
	translate([21,5.1,-1])rotate([0,-60,0])cube(40);
	mirror([1,0,0])translate([21,5.1,-1])rotate([0,-60,0])cube(40);
	translate([0,14,-1])cylinder(r=8,h=5);
	translate([0,6,-1])cube([30,6,6]);
}

