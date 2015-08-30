module miniservo(z){
	//cube([24,14,z]);
	translate([15,7,0])rotate([0,0,0])cylinder(r=8,h=z);
	translate([-1.75,7,0])union(){
		cylinder(r=1.5, h=z,$fn=20);
		translate([27.5,0,0])cylinder(r=1.5, h=z,$fn=20);
		
	}
}

difference(){
	union(){
		cube([34,24,14]);
		translate([0,-15,0])cube([34,15+24+10,2]);
	}

	translate([3,-1,17/2])rotate([-90,0,0]){
		cylinder(r=1.5, h=30,$fn=20);
		translate([27.5,0,0])cylinder(r=1.5, h=30,$fn=20);
	}
	translate([13/2,-1,2])cube([21,21,13]);
	translate([13,-1,13/2+2])rotate([-90,0,0])cylinder(r=1.8,h=60);
	translate([5,-10,-5])cylinder(r=2,h=60);
	translate([29,-10,-5])cylinder(r=2,h=60);
	translate([5,29,-5])cylinder(r=2,h=60);
	translate([29,29,-5])cylinder(r=2,h=60);
	translate([-110,-50,42])rotate([0,45,0])cube(100);



}

