x=1;
d=03.5;

l=5;





difference(){
cube([60,50,32]);
translate([45,-1,40+x])rotate([0,45,0])cube([60,52,32]);
translate([60,-1,-30+x])rotate([0,-45,0])cube([60,52,32]);
translate([36,10,14+x])rotate([0,45,0])cube([40,30,9]);
translate([36,2,10+x])rotate([0,45,0])cube([10,46,21]);
translate([37.5,16,9+x])rotate([0,45,0])cube([10,18,19]);
translate([36,10,14+x])rotate([0,135,0])translate([-4.5,0-d,1])cylinder(r=2,h=20);
translate([36,10,14+x])rotate([0,135,0])translate([-4.5,37-d,1])cylinder(r=2,h=20);



hull(){
	translate([3,-1,3])cube([35,60,26]);
	translate([50,-1,22])rotate([-90,0,0])cylinder(r=6,h=60);
	//translate([54,-1,16+x])cube([3,60,3]);
	//translate([54,-1,21+x])cube([3,60,3]);
	//translate([50,-1,25+x])cube([3,60,3]);
		

}
translate([-5,-1,10])cube([30,60,12]);

}