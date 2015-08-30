use <raid3r/raid3r.scad>

z=2;

rPico=13;

x=9;
y=12;

difference(){
	union(){
		hull(){
			translate([0,0,0])cylinder(r=4,h=z, $fn=8);
			translate([0,48.5,0])cylinder(r=4,h=z, $fn=8);
			translate([65.5-rPico/2,2.5+rPico/2,0])cylinder(r=rPico,h=z, $fn=80);
			translate([65.5-rPico/2,46-rPico/2,0])cylinder(r=rPico,h=z, $fn=80);	
		}
	

	}
	translate([0,0,-1])cylinder(r=3.5/2,h=10, $fn=8);
	translate([0,48.5,-1])cylinder(r=3.5/2,h=10, $fn=8);
	translate([66,45,-1])cylinder(r=3.5/2,h=10, $fn=8);
	translate([66,3.5,-1])cylinder(r=3.5/2,h=10, $fn=8);
	translate([-19,18,-1])cube([24,18,10]);
//Agujeros OpenCM
	translate([0+x,0+y,-1])cylinder(r=3.5/2,h=5, $fn=8);
	translate([60+x,0+y,-1])cylinder(r=3.5/2,h=5, $fn=8);
	translate([0+x,18+y,-1])cylinder(r=3.5/2,h=5, $fn=8);
	translate([60+x,18+y,-1])cylinder(r=3.5/2,h=5, $fn=8);
}