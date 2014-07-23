use <raid3r/raid3r.scad>



module base(){union(){
difference(){
	union(){
		cube([36,34,18]);
		translate([0,17,27])rotate([0,90,0])cylinder(r=6, h=36);

		translate([0,16.5,2])rotate([46,0,0])cube([36,18,23]);
		mirror([0,1,0])translate([0,-17.5,2])rotate([46,0,0])cube([36,18,23]);
	}
		translate([-1,17,27])rotate([0,90,0])cylinder(r=1.5, h=38, $fn=10);
		translate([5,0,20])cube([26,40,40]);
		translate([5,17,27])rotate([0,90,0])cylinder(r=7.5, h=26);
		translate([36-27,5.5,3])cube([36,23,12]);
		translate([36-5,0.5,3])cube([36,33,12]);
		translate([5,10,4])cube([4,36,10]);
		translate([13,3,9])rotate([0,90,0])cylinder(r=1, h=38, $fn=10);
		translate([13,31,9])rotate([0,90,0])cylinder(r=1, h=38, $fn=10);
}

//SOPORTE
/*
		translate([0,16.5,2])rotate([46,0,0])translate([0,5,21.5])cube([36,13,1.5]);
mirror([0,-1,0])translate([0,-17.5,2])rotate([46,0,0])translate([0,5,21.5])cube([36,13,1.5]);
		translate([0,17,31.5])rotate([0,90,0])cylinder(r=1.5, h=36, $fn=10);
/**/
}
}

module pinza(){
difference(){
	union(){
		difference(){
			translate([-4,0,0])cube([60,16,30]);
			translate([26,-23,-1])cylinder(r=30, h=38,$fn=13);
			translate([-20,-6.5,-1])rotate([0,0,35])cube([75,21,38]);
			translate([20,27,-1])rotate([0,0,-30])cube([75,21,38]);
		}
		translate([3,0,0])hull(){
			cylinder(r=6, h=30);
			translate([-10,-2,0])cube([5,13,30]);
	}
}

	

}
}

difference(){
union(){
color("blue",1)translate([0,-1,30])rotate([180,0,0])pinza();
color("blue",1)translate([0,1,0])rotate([0,0,0])pinza();
}

			translate([50,0,-5])cylinder(r=3.5, h=50);
			translate([3,0,15])rotate([0,90,0])cylinder(r=3.5, h=70);
			translate([-17,-6,7])rotate([90,0,90])agujereado(3,3,20);

}