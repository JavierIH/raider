module agujereado(x,y,H){
	union(){
		for(j=[0:y])
		{
			translate([0,j*8,0])
			{
				for(i=[0:x])
				{
					translate([8*i,0,-1])cylinder(r=1.5, h=H, $fn=10);
				}
			}
		}
	}
}

module brazo (){
	rotate([90,0,0])difference(){
		translate([0,0,105])rotate([0,90,0])difference(){
			translate([0,0,-3])cube([105,45,52]);
			//Otro angulo
			translate([9,-20,-5])rotate([0,0,30])cube([25,65,60]);
			//translate([0,2,1.5])rotate([0,0,0])cube([60,65,43]);
			translate([0,-2,1.5])rotate([0,0,0])cube([57,65,43]);
			//translate([63,3,3])rotate([0,0,0])cube([39,65,42]);
			//Eje
			translate([34,13,-4]) cylinder(r=4,h=60);
			//Tornillos del eje
			translate([42,13,-4]) cylinder(r=1.5,h=70);
			translate([26,13,-4]) cylinder(r=1.5,h=70);
			translate([34,21,-4]) cylinder(r=1.5,h=70);
			translate([34,5,-4]) cylinder(r=1.5,h=70);
		}
		translate([15-8,8,0]) agujereado(4,2,100);
	}
}

//Variacion del primer diseño

translate([0,50,0]){
	difference (){
		brazo();
		translate([-70+23,-120,42])rotate([-8,0,0])cube([140,140,140]);
		translate([-50,-44,-20])cube([100,100,100]);
	}
}
