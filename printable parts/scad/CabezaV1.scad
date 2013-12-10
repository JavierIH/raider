module mediaCabeza(){
	translate([0,0,30]) mirror([0,0,1]) difference(){	
		translate([0,-27.5,0]){ difference(){
			cube([55,53,30]);
			rotate([0,-6,0]) translate([0,0,-30]) cube([60,60,30]);
			translate([15,55,0]){rotate([0,0,-24]){cube([100,30,30]);}}}
		}
		translate([0,-60,0])cube([60,60,60]);
		translate([11,0,0])cube([4,23,25]); //Ranura para US
		translate([11,0,22])cube([4,20,3]);} //Ranura para componentes US
}


largoTornillos=28;

difference(){
	union(){
		translate([0,-0.000000000000000000000000001,0]) mediaCabeza();
//Esto ultimo es una chapuza para poder exportar el archivo.
		mirror([0,1,0]) mediaCabeza();
		translate([-20,-25.5,0])cube([20,51,26]);
	}
	translate([5,-5,2]){cube([80,10,4]);} //Canal para cableado
	translate([17.5,0,3])union(){ //tornillos
		cylinder(r=1.35,h=25,$fn=10);
		translate([largoTornillos,0,0])cylinder(r=1.35,h=25,$fn=10);
	}
	translate([15,-12.5/2,25])cube([33,12.5,25.6]); //pestañas del servo
	translate([6,23.25,15])cylinder(r=1.35,h=20, $fn=10);
	translate([6,-23.25,15])cylinder(r=1.35,h=20, $fn=10);
	translate([-10,-43/2,5])cube([25,43,50]);//US HUECOS
	translate([-14,-43/2,3.5])cube([25,43,50]); //US huecos
	translate([-5,-26,25])cube([20,52,40]);//altura delantera
	translate([0,-80,28])cube([80,160,40]);//altura total
	translate([17,-4,3])cube([5,8,20]); //cables montaje servo
	translate([19.5,-7,3])cube([24,14,30]); //montaje servo
	translate([-28,-40,0])rotate([0,15,0])cube([20,80,60]); //cara
}