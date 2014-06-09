p=0.3;

difference(){
union(){
	translate([-17,-10,0])cube([34,20,2]);
	translate([-12,-10,0])cube([24,20,9]);
}
	translate([-7-p/2,-7-p/2,1])cube([14+p,14+p,30]);
	cylinder(r=4.2,h=30,$fn=30,center=true);
	hull(){
	translate([9.5,0,4])cylinder(r=2.3,h=30,$fn=20);
	translate([-9.5,0,4])cylinder(r=2.3,h=30,$fn=20);	
	}
	translate([5,-8,4])cylinder(r=1.1,h=30,$fn=10);
	translate([15,-8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([15,8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([-15,-8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([-15,8,-1])cylinder(r=1.2,h=30,$fn=10);

}