union(){

/*difference(){
	union(){
		translate([-36/2,0,0])cube([36,31,4]);
		translate([-35/2,0,0])cube([35,5,10]);
	}		
	translate([-19/2,-2,1.5])cube([19,40,6]);
	translate([23,5.1,-1])rotate([0,-60,0])cube(40);
	mirror([1,0,0])translate([23,5.1,-1])rotate([0,-60,0])cube(40);
	translate([0,14,-1])cylinder(r=8,h=5);
	translate([0,6,-1])cube([30,6,6]);
	translate([12,27,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([12,16,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([-12,27,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([-12,16,-1])cylinder(r=1.2,h=10, $fn=10);
}*/

difference(){
	translate([-15+40-2.5,12-6,0])cube([30+5,20+6,0.7]);
	translate([12+40,27,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([12+40,16,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([-12+40,27,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([-12+40,16,-1])cylinder(r=1.2,h=10, $fn=10);
	translate([40,23,-1])cylinder(r=4.1,h=10);

}

}