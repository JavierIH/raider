//Medidas camara:
x_cam=38; //fija
y_cam=42;

ancho=x_cam+10;

module eje_micro_servo(){
		translate([-25,0,0])rotate([0,90,0])cylinder(r=2,h=50);

		translate([0,0,0])rotate([0,90,0])cylinder(r=4,h=25);
		translate([0,0,8.5])rotate([0,90,0])cylinder(r=1,h=25,$fn=10);
		hull(){
			translate([x_cam/2+1.5,0,0])rotate([0,90,0])cylinder(r=3.9,h=40);
			translate([x_cam/2+1.5,0,15])rotate([0,90,0])cylinder(r=1.9,h=40,$fn=10);
		}
}

module lifecam (){
	color("red")import("../stl/ChasisLifecam.stl");
	//color("purple")translate([-12,10,1])rotate([90,0,0])cube([24,38,20]);

}

module servo(){
	color("black")import("../stl/CuelloV2.stl");
}

altura=5;
largo=30;
ancho1=13;

module ear(){
	translate([8,-9,45.9])hull(){
		translate([0,0,altura])sphere(0.1);
		translate([ancho1,0,altura])sphere(0.1);
		translate([0,8,altura])sphere(0.1);
		translate([ancho1,8,altura])sphere(0.1);

		translate([2,largo,0])sphere(0.1);
		translate([ancho1-2,largo,0])sphere(0.1);

		translate([-2,0,0])sphere(0.1);
		translate([ancho1+2,0,0])sphere(0.1);
		translate([-2,8,0])sphere(0.1);
		translate([ancho1+2,8,0])sphere(0.1);
	}
}


color("red")
translate([0,9,6])
rotate([0,0,0])
translate([0,-9,-6])
union(){
difference(){

//CUERPO BASE
	translate([-(x_cam+8)/2,-10,0])cube([x_cam+8,68,y_cam+4]);
hull(){
	translate([24,23,0])rotate([0,0,0])cube(80);
	translate([20,37,0])rotate([0,0,0])cube(80);
}
mirror([1,0,0])hull(){
	translate([24,23,0])rotate([0,0,0])cube(80);
	translate([20,37,0])rotate([0,0,0])cube(80);
}

	translate([-35,-1.5,0])rotate([100,0,0])cube([70,68,y_cam+4]);	
	translate([-35,17,-6])rotate([145,0,0])cube([70,68,y_cam+4]);
	//debug
	//translate([0,-10,0])cube([x_cam+9,69,y_cam+5]);


hull(){
	translate([-35,45,-19])
		rotate([15,0,0])cube([70,40,32]);
	translate([-35,25,-32])
		cube([70,40,30]);
}
	

//Cajeado interno
	//translate([-(x_cam-2)/2,-11,-1])cube([x_cam-2,63,y_cam+1]);
	translate([-(x_cam-2)/2,-2,-1])cube([x_cam-2,54,20]);
	//translate([-(x_cam-2)/2,-11,-1])cube([x_cam-2,63,16]);
	translate([-(x_cam-2)/2,-11,20])cube([x_cam-2,65.5,22]);

//Boquete para el cable

	translate([-12,41,21])cube([10,30,8]);
hull(){
	translate([-14,56,25])rotate([-90,0,0])cylinder(r=4,h=30,$fn=30);
	translate([0,56,25])rotate([-90,0,0])cylinder(r=4,h=30,$fn=30);
}
translate([-14,50,25])rotate([-90,0,0])cylinder(r=1,h=30,$fn=10);
	translate([0,50,25])rotate([-90,0,0])cylinder(r=1,h=30,$fn=10);
	


//Eje del servo
	translate([0,9,6])rotate([-45,0,0]) eje_micro_servo();
	translate([x_cam/2-2,5,-1])cube([7,8,7.8]);
}

	translate([0,-2,31])rotate([-90,0,0]){
		//%lifecam();
		difference(){
			translate([-18,-11,2.2])cube([36,22,3]);
			translate([-13,-12,1.2])cube([26,24,9]);
			translate([15,-8,1.2])cylinder(r=1,h=30,$fn=10);
			translate([15,8,1.2])cylinder(r=1,h=30,$fn=10);
			translate([-15,-8,1.2])cylinder(r=1,h=30,$fn=10);
			translate([-15,8,1.2])cylinder(r=1,h=30,$fn=10);
		}
	}

}
	//translate([-17,47+3,0])rotate([0,0,-90])servo();



//ear();
//mirror([1,0,0])ear();

