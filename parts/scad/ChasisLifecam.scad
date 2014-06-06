difference(){
union(){
	translate([-19,-11,0])cube([38,22,2]);
	translate([-13,-11,0])cube([26,22,9]);
}
	translate([-7,-7,1])cube([14,14,30]);
	cylinder(r=4,h=30,$fn=30,center=true);
	hull(){
	translate([9.5,0,4])cylinder(r=2,h=30,$fn=20);
	translate([-9.5,0,4])cylinder(r=2,h=30,$fn=20);	
	}
	translate([6,-9,4])cylinder(r=1.2,h=30,$fn=10);
	translate([16,-8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([16,8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([-16,-8,-1])cylinder(r=1.2,h=30,$fn=10);
	translate([-16,8,-1])cylinder(r=1.2,h=30,$fn=10);

}