use <raid3r/raid3r.scad>



difference()
{
	union(){
		difference(){
			translate([0,4,0])cylinder(r=54,h=10, $fn=10);
			translate([-50,-79,4])cube(100);
			translate([42,0,15.8])rotate([-90,-10,0])cylinder(r=20,h=120,$fn=4);
			translate([-33.9,0,15.8])rotate([-90,10,0])cylinder(r=20,h=120,$fn=4);
			translate([7,41,-14])rotate([0,0,-36])cube([15,14,20]);
			hull(){
				translate([-10,55,0.1])rotate([45,0,0]){
					cube([15,10,14]);
					translate([-5,16,0])cube([15+20,10,14]);
				}
			}

			//hull(){
			//	translate([-14,45,-1])rotate([0,0,-30])cube([15,2,20]);
			//	translate([-12,56,-1])cube([24,2,20]);
			//}

		}
		translate([-12,21,0])cube([24,3,15]);
		mirror([0,1,0])translate([-12,21,0])cube([24,3,15]);
		difference(){
			hull(){	
				translate([-18,-26,0])cube([36,53,8]);
				translate([0,27,28])rotate([90,0,0])cylinder(r=13,h=53);
			}
			translate([-20,-20,4])cube([40,41,60]);
		}
		translate([0,27,4])rotate([90,0,0])cylinder(r=4,h=53,$fn=6);

	}
					translate([0,30,28])rotate([90,0,0])cruz(60);
	translate([34,-50,-5])cube([60,100,20]);
	mirror([1,0,0])translate([26,-50,-5])cube([60,100,20]);
}

//color("blue")translate([-50,55+20,0])cube([100,70,30]);