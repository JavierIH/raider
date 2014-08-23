
module agujereado(X,Y){
	union(){
		for(j=[0:X])
		{
			translate([0,j*8,0])
			{
				for(i=[0:Y])
				{
					translate([i*6,0,-1])union(){
cylinder(r=1.2, h=8, $fn=10);
translate([0,0,3])cylinder(r=2.3, h=5, $fn=10);
}

				}
			}
		}
	}
}
H=5;
module pieza(){
difference(){
union(){
cube([45.5,43,H]);
translate([45.5/2,0,0])cylinder(r=45.5/2,h=H,$fn=4);
}
translate([0,-56.5,-10])cube([45.5,50,100]);
//translate([-1,3,2])cube([47,65,36]);

translate([(45.5-20)/2,5,-1])cube([20,45,40]);
//translate([(45.5-20)/2-4,-2.5,2])cube([28,8,40]);


//translate([0,-20,2])cube([(45.5-32)/2,70,70]);
//translate([45.5-(45.5-32)/2,-20,2])cube([(45.5-32)/2,70,70]);
//translate([22.5,46,0])union(){
//	translate([7,0,-1])cylinder(r=1.5, h=5, $fn=10);
//	translate([-7,0,-1])cylinder(r=1.5, h=5, $fn=10);
//}

translate([3.5,0,0])agujereado(3,0);
translate([3.5+6,16,0])agujereado(3,0);
translate([9.5+26.5,16,0])agujereado(3,0);
translate([9.5+32.5,0,0])agujereado(3,0);
//translate([9.5+32.5,40,0])agujereado(1,0);
//translate([3.5,40,0])agujereado(1,0);



translate([45.5/2,10,-1])cylinder(r=12.6,h=40);
translate([2,34,-1])cylinder(r=6,h=40,$fn=6);
translate([43.5,34,-1])cylinder(r=6,h=40,$fn=6);

//translate([-50,-50,34])cube(100);

}
}

pieza();



