//Medidas camara:
x_cam=20;
y_cam=30;

ancho=x_cam+10;

difference(){
translate([-(x_cam+14)/2,-16.6,0])cube([x_cam+14,78.5,y_cam+3]);
translate([-ancho/2-10,-30,50])rotate([-20,0,0])cube([ancho+20,120,60]);
translate([-ancho/2-10,-9.2,0])rotate([105,0,0])cube([ancho+20,80,60]);
translate([-(x_cam-2)/2,-22,-1])cube([x_cam-2,36,y_cam+1]);
//Cajeado para camara
translate([-x_cam/2,1,-1])cube([x_cam,2,y_cam+1]);
//Cajeado para plaquita
translate([-x_cam/2,-8,-1])cube([x_cam,2,y_cam+1]);
//Hueco para cables
rotate([-90,0,0])translate([0,0,6])cylinder(r=x_cam/2,h=50,$fn=6);
//Taladros
translate([13,0,-1])cylinder(r=1.5,h=14);
translate([13,25,-1])cylinder(r=1.5,h=14);
translate([13,50,-1])cylinder(r=1.5,h=14);
translate([-13,0,-1])cylinder(r=1.5,h=14);
translate([-13,25,-1])cylinder(r=1.5,h=14);
translate([-13,50,-1])cylinder(r=1.5,h=14);
translate([0,-17,-1])cylinder(r=x_cam/2+6,h=y_cam+1, $fn=4);




translate([0,-17,-1])rotate([0,0,0])cylinder(r=5,h=30, $fn=4);




}




