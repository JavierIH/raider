//Medidas camara:
x_cam=38;
y_cam=31;

ancho=x_cam+10;

difference(){
	translate([-(x_cam+8)/2,-16.6,0])cube([x_cam+8,78.5,y_cam+4]);
	translate([-ancho/2-10,-30,50])rotate([-20,0,0])cube([ancho+20,120,60]);

//Cajeado interno
	translate([-(x_cam-2)/2,-22,-1])cube([x_cam-2,36,y_cam+1]);
	translate([-(x_cam-2)/2,8,-1])cube([x_cam-2,50,16]);
	translate([-(x_cam-2)/2,8,14.5])rotate([-20,0,0])cube([x_cam-2,46,16]);

//Cajeado para plaquita
translate([-x_cam/2,-10,-1])cube([x_cam,4,y_cam+1]);


//Eje del servo y cajeado
	translate([0,6,6])rotate([-45,0,0]){
		translate([-25,0,0])rotate([0,90,0])cylinder(r=2,h=50);
		translate([0,0,0])rotate([0,90,0])cylinder(r=4,h=25);
		translate([x_cam/2+1.5,0,15])rotate([0,90,0])cylinder(r=2,h=5,$fn=10);
		translate([x_cam/2+1.5,-1.5,0])cube([7,3,16]);
		translate([x_cam/2+1.5,1,-0.2])rotate([8,0,0])cube([7,3,16]);
		mirror([0,1,0])translate([x_cam/2+1.5,1,-0.2])rotate([8,0,0])cube([7,3,16]);
	}
	translate([x_cam/2-2,2,-1])cube([7,8,7]);

}







