use <raid3r/raid3r.scad>


module screw(d){
translate([0,0,8])rotate([0,180,0])union(){
cylinder(r=5.3/2, h=6, $fn=10);
cylinder(r=2.9/2, h=6+d, $fn=10);
}
}



module bbbholes(z){
union(){
translate([0,0,0])screw(6);
translate([0,41.85,0])screw(6);

translate([0,-3.1,0]){
translate([65.8,0,0])screw(6);
translate([65.8,48.2,0])screw(6);
}


}

}

	difference(){
union(){

		translate([-51,0,0])cube([102,64,4]);
	translate([26,64,0])cube([25,2,6]);
	translate([26,58,0])cube([20,2,6]);
	mirror([1,0,0]){
	translate([26,64,0])cube([25,2,6]);
	translate([26,58,0])cube([20,2,6]);}


}

		translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
		mirror([1,0,0])translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
		translate([78/2,26,0])agujereado(3,1,6);
		mirror([1,0,0])translate([78/2,26,0])agujereado(3,1,6);
		translate([-15-19,12,0])bbbholes(6);
		translate([-4,28,-1]){
		translate([0,0,0])cylinder(r=1.2,h=6);
		translate([8,0,0])cylinder(r=1.2,h=6);
		translate([8,24,0])cylinder(r=1.2,h=6);
		translate([0,24,0])cylinder(r=1.2,h=6);

}
hull(){
		translate([0,20,-1])cylinder(r=3,h=6);
		translate([10,10,-1])cylinder(r=3,h=6);
		translate([-10,10,-1])cylinder(r=3,h=6);
}

	}





