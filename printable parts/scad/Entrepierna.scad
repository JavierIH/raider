
module agujereado(X,Y){
	union(){
		for(j=[0:X])
		{
			translate([0,j*8,0])
			{
				for(i=[0:Y])
				{
					translate([i*6,0,-1])cylinder(r=1.5, h=8, $fn=10);
				}
			}
		}
	}
}

module pieza(){
difference(){
union(){
cube([45.5,52,2]);
translate([45.5/2,0,0])cylinder(r=45.5/2,h=35,$fn=4);
}
rotate([-15,0,0])translate([0,-66,-10])cube([45.5,50,100]);
translate([-1,3,2])cube([47,65,36]);

translate([(45.5-20)/2,-2.5,-1])cube([20,45,40]);
translate([(45.5-20)/2-4,-2.5,2])cube([28,8,40]);


translate([0,-20,2])cube([(45.5-32)/2,70,70]);
translate([45.5-(45.5-32)/2,-20,2])cube([(45.5-32)/2,70,70]);
translate([22.5,46,0])union(){
	translate([7,0,-1])cylinder(r=1.5, h=5, $fn=10);
	translate([-7,0,-1])cylinder(r=1.5, h=5, $fn=10);
}

translate([3.5,0,0])agujereado(6,0);
translate([3.5+6,16,0])agujereado(4,0);
translate([9.5+26.5,16,0])agujereado(4,0);
translate([9.5+32.5,0,0])agujereado(6,0);

translate([45.5/2,10,-1])cylinder(r=12.6,h=40);
//translate([-9.75,30,-1])cylinder(r=12.6,h=40);
//translate([55.25,30,-1])cylinder(r=12.6,h=40);

translate([-50,-50,34])cube(100);

}
}

pieza();



