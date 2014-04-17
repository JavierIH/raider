difference(){
hull(){
cube([50,28,39]);
translate([25-8,30,0])cylinder(r=4,h=39,$fn=4);
translate([25+8,30,0])cylinder(r=4,h=39,$fn=4);
}
translate([-10,2,2])cube([100,38,35]);
translate([25-8,30,-1])cylinder(r=1.5,h=41,$fn=10);
translate([25+8,30,-1])cylinder(r=1.5,h=41,$fn=10);

}