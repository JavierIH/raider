use <raid3r/raid3r.scad>


//servo  34+5+5=44
//Ancho externo de la cabeza 44
//Ancho interno de la cabeza 36
//Ancho de la placa de la camara 38


module agujereado(X,Y,H){
	union(){
		for(j=[0:X])
		{
			translate([0,j*8,0])
			{
				for(i=[0:Y])
				{
					translate([i*6,0,-1])cylinder(r=1.2, h=H, $fn=10);
				}
			}
		}
	}
}

offset=5;


rotate([0,0,0])
difference(){
union(){
translate([0,0,-2])cube([50,34,17]);
hull(){
translate([30,-16,-2])cube([7,66,2]);
translate([0,0,-2])cube([1,34,2]);
}

}
	//cube([50,34,15]);
	//translate([24+offset,17,-1])rotate([0,0,90]){
		//translate([16,0,0])agujereado(3,0,20);
		//mirror([1,0,0])translate([16,0,0])agujereado(3,0,20);
	//}
	translate([24,5,-0.01])cube([23,50,13]);
	translate([18,25,-0.01])cube([50,50,13]);
	translate([30,5,-0.01])cube([50,8,13]);
	translate([45,6,-5])cube([50,50,13]);
	translate([44,25,7])cube([50,50,13]);

	translate([21,17,13/2])rotate([-90,0,0])cylinder(r=1,h=20,$fn=10);
	translate([41,-1,13/2])rotate([-90,0,0])cylinder(r=1.5,h=40,$fn=10);
	translate([41,2.5,13/2])rotate([-90,0,0])cylinder(r=5.5/2,h=40,$fn=10);
	translate([-3,2,1])rotate([0,0,0])cube([18,29,40]);
	translate([-21,2-5,3])rotate([0,45,0])cube([14,29+10,40]);
translate([6,17-8,-2])agujereado(2,1,90);
translate([33,-16+4,-5])cylinder(r=1.8,h=10);
translate([33,50-4,-5])cylinder(r=1.8,h=10);

}

