module separador(){
difference(){
hull(){
cylinder(r=6,h=3);
cylinder(r=4,h=8);
}
translate([0,0,-1])cylinder(r=2,h=10);
translate([0,0,1])cylinder(r=3,h=10);
}
}

translate([0,0,0])separador();
translate([15,0,0])separador();
translate([15,15,0])separador();
translate([0,15,0])separador();