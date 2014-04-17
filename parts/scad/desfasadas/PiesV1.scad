module sensor(){

cube([28.4,28.4,6]);

	
}

module bracket(){
	//translate([0,0,25])rotate([90,0,0])import_stl("F2.stl");
}

module refuerzo(){
	difference(){
		translate([0,0,0])cube([16,3,16]);
		translate([0,5,16])rotate([90,0,0])cylinder(r=16,h=8,$fn=8);
		translate([-50,-50,14])cube(100);
	}
}

module refuerzo2(){
	difference(){
		translate([1,0,0])cube([19,3,19]);
		translate([-18,5,23])rotate([90,0,0])cylinder(r=40,h=8,$fn=4);
		//translate([-50,-50,17])cube(100);
	}
}

module agujero(){
	translate(0,0-1)cylinder(r=4,h=8);
}

x=27;
y=22;

rotate([0,0,90])
difference(){
union(){
difference()
{
	union(){
		difference(){
			translate([0,4,0])cylinder(r=54,h=10, $fn=10);
			translate([0,-36,4])cylinder(r2=76,r1=56,h=20, $fn=10);
			}
			
		bracket();
		translate([-27,21,3.9])refuerzo2();
		mirror([1,0,0])translate([-27,21,3.9])refuerzo2();
		mirror([0,1,0])mirror([1,0,0])translate([-27,21,3.9])refuerzo2();
		mirror([0,1,0])translate([-27,21,3.9])refuerzo2();

		translate([-12,21,0])cube([24,3,15]);
		mirror([0,1,0])translate([-12,21,0])cube([24,3,15]);

		rotate([0,0,90])mirror([0,1,0])translate([-39,9,3.9])refuerzo();
		mirror([1,0,0])rotate([0,0,90])mirror([0,1,0])translate([-39,9,3.9])refuerzo();
	}

	translate([34,-50,0])cube([60,100,10]);
	mirror([1,0,0])translate([26,-50,0])cube([60,100,10]);
	

	translate([-x/2,40-y/2,-1])cube([x,y,15]);
	translate([-29/2,40-29/2,8])cube([29,29,5]);

	
	translate([-100,-100,-200])cube(200);


	
}
//union
	difference(){
	translate([-29/2,40-29/2,0])cylinder(r=7,h=8);
	translate([-29/2-50,40-29/2-100,0])cube(100);
	}
	difference(){
	translate([-29/2+29,40-29/2,0])cylinder(r=7,h=8);
	translate([-29/2-50+29,40-29/2-100,0])cube(100);
	}
	difference(){
	translate([-29/2,40-29/2+29,0])cylinder(r=7,h=8);
	translate([-29/2-50,40-29/2+26,0])cube(100);
	}
	difference(){
	translate([-29/2+29,40-29/2+29,0])cylinder(r=7,h=8);
	translate([-29/2-50,40-29/2+26,0])cube(100);
	}



}
//diff
translate([42,0,18])rotate([0,90,90])cylinder(r=20,h=120,$fn=4);
translate([-33.9,0,18])rotate([0,90,90])cylinder(r=20,h=120,$fn=4);

	translate([-29/2+2.5,40-29/2+2.5,-1])cylinder(r=1.5,h=10);
	

	translate([-29/2+29-2.5,40-29/2+2.5,-1])cylinder(r=1.5,h=10);
	
	translate([-29/2+2.5,40-29/2+29-2.5,-1])cylinder(r=1.5,h=10);
	
	translate([-29/2+29-2.5,40-29/2+29-2.5,-1])cylinder(r=1.5,h=10);
	

}

//sensor();
