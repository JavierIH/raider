//Medidas camara:
x_cam=38; //fija
y_cam=42;

ancho=x_cam+10;

module eje_micro_servo(){
		translate([-25,0,0])rotate([0,90,0])cylinder(r=2,h=50);

		translate([0,0,0])rotate([0,90,0])cylinder(r=4,h=25);
		hull(){
		translate([x_cam/2+1.5,0,0])rotate([0,90,0])cylinder(r=4,h=40);
		translate([x_cam/2+1.5,0,15])rotate([0,90,0])cylinder(r=2,h=40,$fn=10);
		}

	}

module lifecam (){
color("purple")cube([24,38,20]);
}

module servo(){
color("blue")import("../stl/CuelloV2.stl");
}

translate([0,9,6])
rotate([0,0,0])
translate([0,-9,-6]){
difference(){

//CUERPO BASE
	translate([-(x_cam+8)/2,-10,0])cube([x_cam+8,68,y_cam+4]);
	translate([-35,-1,0])rotate([100,0,0])cube([70,68,y_cam+4]);
	
translate([-35,17,-6])rotate([145,0,0])cube([70,68,y_cam+4]);

	//%translate([-35,-1,0])rotate([0,0,0])cube([70,70,70]);
hull(){
	translate([-35,45,-19])
		rotate([15,0,0])cube([70,40,32]);
	translate([-35,25,-32])
		cube([70,40,30]);
}
	

//Cajeado interno
	translate([-(x_cam-2)/2,-11,-1])cube([x_cam-2,63,y_cam+1]);


//Eje del servo
	translate([0,9,6])rotate([-45,0,0]) eje_micro_servo();
	translate([x_cam/2-2,5,-1])cube([7,8,7.8]);
}

	translate([-12,6,15+6])lifecam();

}
	translate([-17,47+3,0])rotate([0,0,-90])servo();









