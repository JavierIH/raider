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


//for(i=[0:10]){
translate([14*i,0,0])casquillo(6,4,7.2);
//}