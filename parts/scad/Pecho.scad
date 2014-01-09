use <raid3r/raid3r.scad>

difference(){
	translate([-51,0,0])cube([102,64,38]);
	translate([2.7-51,8,3])cube([102-2.7*2,53,43+1]);
	translate([-5-51,48,19])rotate([0,-90,-180])dynahole(140);
	translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
	mirror([1,0,0])translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
	translate([0,30,8])cylinder(r=30,h=50,$fn=6);
	translate([0,-5,19])rotate([-90,0,0])cruz(14);
	translate([0,66,22])rotate([0,270,90])miniservo(9);
	translate([16,66,7])rotate([90,0,0])agujereado(4,2,10);
	mirror([1,0,0])translate([16,66,7])rotate([90,0,0])agujereado(4,2,10);
translate([-70,15.5,19])cube([140,44,50]);

}



