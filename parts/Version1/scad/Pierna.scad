espesor=4.5;

module tornillo(d){
	union(){
		rotate([0,90,0])cylinder(r=1.2,h=60,$fn=10);
		translate([-1-d,0,0])rotate([0,90,0])cylinder(r=2.1,h=10,$fn=10);
		translate([51+d,0,0])rotate([0,90,0])cylinder(r=2.1,h=10,$fn=10);


	}
}

module eje(){
	rotate([0,90,0])cylinder(r=4,h=60,$fn=20);
	translate([0,-8,0])tornillo(2);
	translate([0,8,0])tornillo(2);
	translate([0,0,8])tornillo(2);
	translate([0,0,-8])tornillo(2);
}

module agujeros_servo(){
	translate([0,0,-8]) tornillo(-3);
	translate([0,0,0]) tornillo(-3);
	translate([0,0,8]) tornillo(-3);
	translate([0,0,16]) tornillo(-3);
	translate([0,5.3,22]) tornillo(-3);
	translate([0,5.3+16,22]) tornillo(-3);
}

y=32;
union(){
translate([0,0,12])
difference(){
	hull(){
	translate([-(42+espesor*2)/2,-12+y,-12])cube([42+espesor*2,113-y,40+espesor]);
	translate([-25.5,0,0])rotate([0,90,0])cylinder(r=12,h=51);
	translate([-51/2,-8,-12])cube([51,5,4]);
	translate([-51/2,-4,-12])cube([51,4,1]);
	}
	rotate([-10,0,0])translate([-50,0,40])cube(100);
	translate([-32/2,53,-21])cube([32,32,46]);
	translate([-19.5,59,-19])cube([39,50,38]);
	translate([-42/2,-38,-13])cube([42,44+42+2,43]);
	translate([-30,0,0])eje();

	translate([-30,56,0])agujeros_servo();
	//%translate([-30,-72,28])rotate([-45,0,0])cube([60,60,80]);
	//%translate([-30,-72,-27])rotate([-45,0,0])cube([60,60,60]);
	translate([-30,36,-48])rotate([-30,0,0])cube([60,60,75]);
	translate([-30,73.5,-58])rotate([0,0,0])cube([60,60,75]);
	//translate([-50,-111,-12])cube(100);
}
//SOPORTES


%translate([7,18.5,0])cube([2,30,43]);
%mirror([10,0,0])translate([7,18.5,0])cube([2,30,43]);

%translate([7,54,0])cube([2,30,37]);
%mirror([10,0,0])translate([7,54,0])cube([2,30,37]);

%translate([7,87,0])cube([1.5,14,35]);
%mirror([10,0,0])translate([7,87,0])cube([1.5,14,35]);

%translate([25.5,98,0])rotate([0,0,90])cube([1.5,51,35]);



}