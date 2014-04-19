use <raid3r/raid3r.scad>

x=-1;
d=03.5;
l=5;
r=90;

difference(){
cube([30,50,32]);
translate([15,-1,46+x])rotate([0,45,0])cube([60,52,32]);
translate([30,-1,-30+x])rotate([0,-38,0])cube([60,52,32]);
translate([6,10,14+x])rotate([0,45,0])cube([40,30,9]);
//translate([6.5,-2,10.5+x])rotate([0,45,0])cube([10,54,19]);
translate([7.5,16,9+x])rotate([0,45,0])translate([0,0,3])cube([10,18,16]);
translate([18,12,12+x])cube([10,26,12]);
translate([6,10,14+x])rotate([0,135,0])translate([-4.5,0-d,1])cylinder(r=2,h=20);
translate([6,10,14+x])rotate([0,135,0])translate([-4.5,37-d,1])cylinder(r=2,h=20);



hull(){
	//translate([3,-1,3])cube([10,60,26]);
	translate([5,-1,27])rotate([-90,0,0])cylinder(r=2,h=60,$fn=20);
	translate([5,-1,5])rotate([-90,0,0])cylinder(r=2,h=60,$fn=20);
	translate([13.5,-1,5])rotate([-90,0,0])cylinder(r=2,h=60,$fn=20);
	translate([25,-1,17])rotate([-90,0,0])cylinder(r=2,h=60,$fn=20);
	translate([25,-1,27])rotate([-90,0,0])cylinder(r=2,h=60,$fn=20);
	//translate([17,-1,17+x])cube([10,60,12]);

	//translate([54,-1,16+x])cube([3,60,3]);
	//translate([54,-1,21+x])cube([3,60,3]);
	//translate([50,-1,25+x])cube([3,60,3]);
		

}
translate([26,17,26])rotate([0,90,0])agujereado(3,3,6);

translate([-2,-1,13])cube([10,60,6]);

translate([-1,25-16,(32+16)/2])rotate([0,90,0]){
cylinder(r=1.8,h=10,$fn=10);
translate([16,0,0])cylinder(r=1.8,h=10,$fn=10);
translate([16,32,0])cylinder(r=1.8,h=10,$fn=10);
translate([0,32,0])cylinder(r=1.8,h=10,$fn=10);
	}


//cortes inclinados
translate([0,25,0]){
rotate([0,0,40])translate([-30,-r,-1])cube(60);
mirror([0,1,0])rotate([0,0,40])translate([-30,-r,-1])cube(60);
	}

}