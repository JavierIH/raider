/*Pequeña biblioteca con las funciones mas comunes*/

module agujereado(X,Y,H){
	union(){
		for(j=[0:X-1])
		{
			translate([0,j*8,0])
			{
				for(i=[0:Y-1])
				{
					translate([i*6,0,-1])cylinder(r=1.2, h=H, $fn=10);
				}
			}
		}
	}
}

module dynahole(H){
	translate([-45.5/2,-10,1])union(){
		translate([3.5+6,16,0])agujereado(4,1,H);
		translate([9.5+26.5,16,0])agujereado(4,1,H);
		translate([45.5/2,10,-1])cylinder(r=11.5,h=H);	
		translate([(45.5-20)/2,6.5,-1])cube([20,36,H]);
		translate([22.5,46,0])union(){
			translate([7,0,-1])cylinder(r=1.5, h=H, $fn=10);
			translate([-7,0,-1])cylinder(r=1.5, h=H, $fn=10);
		}
	}
}

module cruz(H){
	translate([-34,-13,3])union(){
		translate([34,13,-3]) cylinder(r=4,h=H);
		translate([42,13,-3]) cylinder(r=1.5,h=H);
		translate([26,13,-3]) cylinder(r=1.5,h=H);
		translate([34,21,-3]) cylinder(r=1.5,h=H);
		translate([34,5,-3]) cylinder(r=1.5,h=H);
	}
}

module miniservo(H){
	translate([-15,-7,0])union(){
		translate([15,7,0])rotate([0,0,0])cylinder(r=8,h=H);
		translate([-1.75,7,0])union(){
			cylinder(r=1.5, h=H,$fn=20);
			translate([27.5,0,0])cylinder(r=1.5, h=H,$fn=20);
		}
	}
}
