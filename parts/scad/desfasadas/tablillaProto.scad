module brocaFresada(){
	translate([0,0,-1]){
		union(){
			cylinder(r=3/2, h=6, $fn=10);
			translate([0,0,3])cylinder(r=7/2, h=3, $fn=10);
		}			
	}
}

module brocaPlaca(){
	union(){
		brocaFresada();
		translate([0,48,0])brocaFresada();
		translate([48,0,0])brocaFresada();
		translate([48,48,0])brocaFresada();
	}
}

	dist=8;
	i=0;
	j=0;

module agujereado(){
	union(){
		for(j=[0:6])
		{
			translate([0,j*dist,0])
			{
				for(i=[0:10])
				{
					translate([dist*i,0,-1])cylinder(r=1.5, h=5, $fn=10);
				}
			}
		}
	}
}

module cuarto(){
	translate([3,0,0]){
		union(){
		cube([42,29,4]);
		translate(3,0,0){rotate([0,0,21]){cube([3,8.5,4]);}}	
		translate([-3,8,0]){cube([3,21,4]);}
		}
	}
}

module base(){
	union(){	
		cuarto();
		translate([90,0,0]){mirror([1,0,0]){cuarto();}}
		translate([0,58,0]){mirror([0,1,0]){cuarto();}}
		translate([90,58,0]){mirror([1,0,0]){mirror([0,1,0]){cuarto();}}}
	}
}

difference(){
union(){
difference(){
	base();
	translate([5,5,0]) agujereado();
	translate([33,5,0])brocaPlaca();
	translate([0,0,3])cube(200);
	//translate([34,0,-5])cube([22,25,10]); //boquete para cables
}

translate([33,39,0])cube([24,5,25]);
translate([33,27,0])cube([24,5,25]);
}
translate([35,42,0])cube([20,8,32]);
translate([35,30,0])cube([20,8,32]);
translate([35,8,0])cube([20,16,32]);

translate([37,20,20])rotate([-90,0,0])union(){
cylinder(r=1.5, h=100,$fn=10);
translate([16,0,0])cylinder(r=1.5, h=100,$fn=10);
}

}

