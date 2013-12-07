module agujereado(x,y){
	union(){
		for(j=[0:y-1])
		{
			translate([0,j*8,0])
			{
				for(i=[0:x-1])
				{
					translate([8*i,0,-1])cylinder(r=1.5, h=30, $fn=10);
				}
			}
		}
	}
}


module lateral(){
	rotate([90,0,0]) difference(){
		cube([21.5,25,8]);
		translate([3,0,3]) cube([24,25,9]);
		translate([10.5,4.5,0]) agujereado(2,3);
		translate([0,4.5,5.5]) rotate([0,90,0]) agujereado(1,3);
	}
}

difference(){
	union(){
		lateral();
		translate([0,-(11+27),0]) mirror([0,1,0]) lateral();
		translate([8,-38,0]) cube([4,38,25]);
	}
	translate([5,-6,5]) rotate([0,90,0]) cylinder(r=3,h=20);
	translate([5,-6,13]) rotate([0,90,0]) cylinder(r=3,h=20);
	translate([5,-6,21]) rotate([0,90,0]) cylinder(r=3,h=20);
	translate([5,-32,5]) rotate([0,90,0]) cylinder(r=3,h=20);
	translate([5,-32,13]) rotate([0,90,0]) cylinder(r=3,h=20);
	translate([5,-32,21]) rotate([0,90,0]) cylinder(r=3,h=20);
}