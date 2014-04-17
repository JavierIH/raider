module agujereado(x,y){
	union(){
		for(j=[0:y])
		{
			translate([0,j*8,0])
			{
				for(i=[0:x])
				{
					translate([8*i,0,-1])cylinder(r=1.5, h=5, $fn=10);
				}
			}
		}
	}
}

module brazo (){ difference(){
	rotate([90,0,0])difference(){
		translate([0,0,105])rotate([0,90,0])difference(){
			translate([0,0,-2])cube([105,45,50]);
			//Un angulo
			translate([0,45,0])rotate([0,0,-8])cube([140,30,60]);
			//Otro angulo
			translate([9,-20,-5])rotate([0,0,30])cube([25,65,60]);
			//translate([0,2,1.5])rotate([0,0,0])cube([60,65,43]);
			translate([0,-2,1.5])rotate([0,0,0])cube([57,65,43]);
			//translate([63,3,3])rotate([0,0,0])cube([39,65,42]);
			//Eje
			translate([34,13,-3]) cylinder(r=4,h=60);
			//Tornillos del eje
			translate([42,13,-3]) cylinder(r=1.5,h=60);
			translate([26,13,-3]) cylinder(r=1.5,h=60);
			translate([34,21,-3]) cylinder(r=1.5,h=60);
			translate([34,5,-3]) cylinder(r=1.5,h=60);
			//Agujeros laterales
			translate([88,13,-3]) cylinder(r=6,h=60);
			translate([70,16,-3]) cylinder(r=6,h=60);
			translate([52,19,-3]) cylinder(r=6,h=60);
		}
		translate([15,5,0]) agujereado(2,2);
		translate([13,15,38]) cylinder(r=8,h=90);
		translate([33,15,38]) cylinder(r=8,h=90);

	}
	translate([7,-38,0])agujereado(4,1);
	translate([15,-22,0])agujereado(2,2);
	}
}

//Variacion del primer diseño

difference (){
	translate([-46/2,0,0]) brazo();
	translate([12,0,0])rotate([0,0,-76])cube([140,20,60]);
	mirror ([1,0,0])translate([12,0,0])rotate([0,0,-76])cube([140,20,60]);
	translate([-70,-120,42])rotate([-8,0,0])cube([140,140,140]);
	translate([-10,-43,2]) cube([20,40,60]);
	translate([10,-43,2]) rotate([0,0,14]) cube([10,39,60]);
	mirror([1,0,0]) translate([10,-43,2]) rotate([0,0,14]) cube([10,39,60]);
}
