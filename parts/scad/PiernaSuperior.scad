use <raid3r/raid3r.scad>


module pata(){difference(){
hull(){
translate([51,11,0])cylinder(r=11, h=3.5);
translate([-22,11+14,0])cylinder(r=11, h=3.5);
translate([-19,-1,0])cube([46,24,3.5]);
}
translate([51,11,-1])cruz(8);
translate([-22,11+14,-1])cruz(8);
translate([0,7,-1])cylinder(r=2, h=5);
translate([0,24,-1])cylinder(r=2, h=5);
}
}

pata();
translate([0,-4,0])mirror([0,1,0]) pata();