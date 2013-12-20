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

module dynahole(H){
	translate([-45.5/2,-10,1])union(){
		translate([3.5+6,16,0])agujereado(3,0,H);
		translate([9.5+26.5,16,0])agujereado(3,0,H);
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


difference(){
	translate([-51,0,0])cube([102,64,38]);
	translate([2.7-51,8,3])cube([102-2.7*2,53,43+1]);
	translate([-5-51,48,19])rotate([0,-90,-180])dynahole(140);
	translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
	mirror([1,0,0])translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
	translate([0,30,8])cylinder(r=30,h=50,$fn=6);
	translate([0,-5,19])rotate([-90,0,0])cruz(14);
	translate([0,66,22])rotate([0,270,90])miniservo(9);
	translate([16,66,7])rotate([90,0,0])agujereado(3,1,10);
	mirror([1,0,0])translate([16,66,7])rotate([90,0,0])agujereado(3,1,10);
translate([-70,15.5,19])cube([140,44,50]);

}



