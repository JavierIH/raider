use <raid3r/raid3r.scad>


		   d=33.6;

difference()
{
    union(){
        translate([0,2,0])cylinder(r=54,h=4, $fn=10);
        difference(){
            union(){
                hull(){	
                    translate([-18,-26,0])cube([36,51,4]);
                    translate([0,25,28])rotate([90,0,0])cylinder(r=13,h=51);

                }
                hull(){	
                    translate([-13,-26,28])cube([26,51,1]);
                    translate([-18,-26,0])cube([36,51,4]);
        		       translate([0,30,4])rotate([90,0,0])cylinder(r=0.0001,h=61,$fn=4);

                }
            }
            translate([-20,-20,4])cube([40,39,60]);
            translate([0,25+51,28])rotate([90,0,0])cylinder(r=13,h=51);
            translate([0,25-51,28])rotate([90,0,0])cylinder(r=13,h=51);
        }
        translate([0,25,4])rotate([90,0,0])cylinder(r=4,h=51,$fn=6);
        hull(){
            translate([-d/2,19,4])rotate([0,90,0])cylinder(r=6,h=d,$fn=4);
            translate([-36/2,19,4])rotate([0,90,0])cylinder(r=0.01,h=36,$fn=4);
        }
        hull(){
            translate([-d/2,-20,4])rotate([0,90,0])cylinder(r=6,h=d,$fn=4);
            translate([-36/2,-20,4])rotate([0,90,0])cylinder(r=0.01,h=36,$fn=4);
        }		
    }
    translate([0,30,28])rotate([90,0,0])cruz(60);
    translate([34,-50,-5])cube([60,100,20]);
    mirror([1,0,0])translate([26,-50,-5])cube([60,100,20]);
    translate([0,0,-100])cube(200,center=true);
    
}

//color("blue")translate([-50,55+20,0])cube([100,70,30]);