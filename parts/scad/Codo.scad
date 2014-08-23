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
			translate([0,0,-2])cube([61,70,50-2]);
			//Otro angulo
			translate([9+2,-20,-5])rotate([0,0,30])cube([25,65,60]);
			translate([0,-2,2])cube([57,65,40]);
			rotate([0,0,-8])translate([28-46,10,-10]) cube([40,40,20]);

			//Eje
			translate([34+2,13,-4]) cylinder(r=4.2,h=60,$fn=20);
			//Tornillos del eje
			translate([42+2,13,-10]) cylinder(r=1.1,h=70,$fn=20);
			translate([26+2,13,4]) cylinder(r=1.1,h=70,$fn=20);
			translate([34+2,21,4]) cylinder(r=1.1,h=70,$fn=20);
			translate([34+2,5,4]) cylinder(r=1.1,h=70,$fn=20);
			
		}
		translate([14-8,8,0]) cylinder(r=1.5, h=100, $fn=10);
		translate([14-8+32,8,0]) cylinder(r=1.5, h=100, $fn=10);
		translate([14-8,8+16,0]) cylinder(r=1.5, h=100, $fn=10);
		translate([14-8+32,8+16,0]) cylinder(r=1.5, h=100, $fn=10);
	}
}

//Variacion del primer diseño

mirror([0,1,0])rotate([188,0,0])translate([0,50,0]){
	difference (){
		brazo();
		translate([-70+23,-120,42])rotate([-8,0,0])cube([140,140,140]);
	}
}
