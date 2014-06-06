p=0.3;

difference(){
union(){
	translate([-18,-11,0])cube([36,22,2]);
	translate([-13,-11,0])cube([26,22,9]);
}
	translate([-7-p/2,-7-p/2,1])cube([14+p,14+p,30]);
	cylinder(r=4.2,h=30,$fn=30,center=true);
	hull(){
	translate([9.5,0,4])cylinder(r=2.3,h=30,$fn=20);
	translate([-9.5,0,4])cylinder(r=2.3,h=30,$fn=20);	
	}
	translate([6,-9,4])cylinder(r=1.1,h=30,$fn=10);
	translate([15,-8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([15,8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([-15,-8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([-15,8,-1])cylinder(r=1.2,h=30,$fn=10);

}