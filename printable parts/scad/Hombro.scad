module cruz(H){
	translate([-34,-13,3])union(){
		translate([34,13,-3]) cylinder(r=4,h=H);
		translate([42,13,-3]) cylinder(r=1.5,h=H);
		translate([26,13,-3]) cylinder(r=1.5,h=H);
		translate([34,21,-3]) cylinder(r=1.5,h=H);
		translate([34,5,-3]) cylinder(r=1.5,h=H);
	}
}

difference(){
	cube([50,50,50]);
	translate([-5,23,13])rotate([0,90,0])cruz(60);
	translate([25,-5,14])rotate([-90,0,0])cruz(60);
	translate([-1,-20,30])rotate([10,0,0])cube(70);
	translate([-1,40,0])rotate([-20,0,0])cube(70);

	translate([4,14,-12])rotate([10,0,0])cube([42,14,42.2]);
	translate([4,20,-10])rotate([0,0,0])cube([42,46,42]);
	translate([4,4,-15])cube([42,42,44.5]);
	translate([-5,-5,37])cube(60);


}