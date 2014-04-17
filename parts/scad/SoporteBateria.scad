difference(){
hull(){
cube([70,28,39]);
translate([35-8,30,0])cylinder(r=4,h=39,$fn=4);
translate([35+8,30,0])cylinder(r=4,h=39,$fn=4);
}
translate([-10,2,2])cube([100,24,35]);
translate([35-8,30,-1])cylinder(r=1.5,h=41,$fn=10);
translate([35+8,30,-1])cylinder(r=1.5,h=41,$fn=10);

}