module brocaFresada(){
	translate([0,0,-1]){
		union(){
			cylinder(r=3/2, h=6, $fn=10);
			translate([0,0,3])cylinder(r=5/2, h=3, $fn=10);
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

i=0;
l=8;
difference(){
difference(){
	union(){
		cube([54,54,3]);
		translate(3,3,0)cylinder(r=)
	}
	translate([3,3,0])brocaPlaca();

}
	for(i=[0:5]){
		translate([5+i*l,7,0])cube([4,40,3]);
	}
}
