//Casquillos

//Basico
module casquillo(cabeza,ancho,largo){
difference(){
union(){
cylinder(r=ancho,h=largo,$fn=100);
cylinder(r=cabeza,h=1.5,$fn=100);
}
translate([0,0,-1])cylinder(r=1.6,h=10,$fn=100);
}
}

module casquilloPies(){
difference(){
union(){
translate([0,0,-1])cylinder(r=4,h=10.2,$fn=100);
hull(){
translate([0,0,7.7])cylinder(r=6,h=1.5,$fn=100);
translate([0,0,7.7+3])cylinder(r=5.5,h=1,$fn=100);
}
}
translate([0,0,-1])cylinder(r=1.7,h=30,$fn=100);
translate([0,0,11.7-2])cylinder(r=3,h=30,$fn=100);
}
}


casquilloPies();