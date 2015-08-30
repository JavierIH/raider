module cruz(H){
	d=8;
	union(){
		cylinder(r=4,h=H);
		translate([+d,0,0]) cylinder(r=1.5,h=H,$fn=10);
		translate([-d,0,0]) cylinder(r=1.5,h=H,$fn=10);
		translate([0,+d,0]) cylinder(r=1.5,h=H,$fn=10);
		translate([0,-d,0]) cylinder(r=1.5,h=H,$fn=10);
	}
}

rotate([90,0,0])difference(){
	cube([50,50,50]);
	translate([-5,23,14])rotate([0,90,0])cruz(60);
	translate([25,-5,14])rotate([-90,0,0])cruz(60);
	translate([-1,-20,30])rotate([10,0,0])cube(70);
	translate([-1,40,0])rotate([-20,0,0])cube(70);
	translate([4,14,-12])rotate([10,0,0])cube([42,14,42.2]);
	translate([4,20,-10])rotate([0,0,0])cube([42,46,42]);
	translate([4,4,-15])cube([42,42,44.5]);
	translate([-5,-5,37])cube(60);
}
