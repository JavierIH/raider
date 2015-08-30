use <raid3r/raid3r.scad>

z=2;
x=6;
y=46.5/2-8;
difference(){
	union(){
		hull(){
			translate([0,-1,0])cylinder(r=3.5,h=z, $fn=8);
			translate([0+x,0+y,0])cylinder(r=3.5,h=z+2.5, $fn=8);
		}
		hull(){
			translate([66,44,0])cylinder(r=3.5,h=z, $fn=8);
			translate([60+x,18+y,0])cylinder(r=3.5,h=z+2.5, $fn=8);
		}
		hull(){
			translate([0,47.5,0])cylinder(r=3.5,h=z, $fn=8);
			translate([0+x,18+y,0])cylinder(r=3.5,h=z+2.5, $fn=8);
		}
		hull(){
			translate([66,2.5,0])cylinder(r=3.5,h=z, $fn=8);
			translate([60+x,0+y,0])cylinder(r=3.5,h=z+2.5, $fn=8);
		}
		hull(){
			translate([0+x,0+y,0])cylinder(r=3.5,h=z, $fn=8);
			translate([60+x,0+y,0])cylinder(r=3.5,h=z, $fn=8);
			translate([0+x,18+y,0])cylinder(r=3.5,h=z, $fn=8);
			translate([60+x,18+y,0])cylinder(r=3.5,h=z, $fn=8);
		}
	}
	translate([0+x,0+y,-1])cylinder(r=2,h=z+6, $fn=8);
	translate([60+x,0+y,-1])cylinder(r=2,h=z+6, $fn=8);
	translate([0+x,18+y,-1])cylinder(r=2,h=z+6, $fn=8);
	translate([60+x,18+y,-1])cylinder(r=2,h=z+6, $fn=8);
	translate([0,-1,-1])cylinder(r=2,h=z+2, $fn=8);
	translate([0,47.5,-1])cylinder(r=2,h=z+2, $fn=8);
	translate([66,2.5,-1])cylinder(r=2,h=z+2, $fn=8);
	translate([66,44,-1])cylinder(r=2,h=z+2, $fn=8);
}

