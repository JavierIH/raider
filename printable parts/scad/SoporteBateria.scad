	difference(){
		translate([-31/2,0,0]){
			difference(){
				union(){
					cube([31,30,28]); //cambiar por 31
					translate([-2,21.5,0])cube([3,5,28]);
					translate([30,21.5,0])cube([3,5,28]);	
				}
				translate([5,3,-1])cube([21,50,30]);
				//translate([27/2,20,14])rotate([90,45,0])cylinder(r=6,h=40, $fn=4);
				translate([11.5,-15,7])cube([8,30,14]);
			}
		}
		translate([14,25,0])rotate([0,0,40])translate([0,-8,0])cube(100);
		mirror([1,0,0])translate([14,25,0])rotate([0,0,40])translate([0,-8,0])cube(100);
		translate([-50,28,0])cube(200);
	}
	//translate([11.5,22,0])cube([3,5,28]);
	//mirror([1,0,0])translate([11.5,22,0])cube([3,5,28]);

