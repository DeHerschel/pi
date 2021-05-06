
/*
This is the method the Greeks used to calculate PI. 
It consists of adding sides to two polygons until they are close enough to a circle to calculate pi.

Here you can see an animation with which you can interact increasing or decreasing then number of sides

https://www.geogebra.org/m/BhxyBJUZ


There is an inscribed polygone inside a circunference with radius r. On this circunference there is circunscribed polygone. 
Both polygones with 2n sides.  

From the center are traced two lines directed to two contigous vertices forming a triangle:
  
                                                          _____________________ (vertice B)
                                                          \     d   |         /
                                                           \________|________/ h2(OB)
                                                (vertice A) \   l   |       /
                                                             \      |      /
                                                              \     |r ---/-------> radius of the circunfeerence
                                                        h1(OA) \    |    /
                                                                \   |   /
                                                                 \  |  /
                                                                  \ | /
                                                                   \ /  <-----------angle "ang"
                                                                    .
                                                                  center (O)
    l: half side of the internal polygone Side = 2l
    d: half side of the external polygon
    ang: angule formed by OA y OB. If the polytgon have n sides, then 1rad=ang*n so ang = 2pi/n
 
 Now we need to caltulate the perimeters of the n sides polyhones.
 To calculate the perimeters, first we need to know l and d.
 
 Basical trigonometry:
 
                l = r * sin(pi/n) 
                d = r * tan(pi/n)
 
 So, the perimeter is side*n(sides).
 
            P(A_n) = 2nr*sin(pi/n)         P(B_n) = 2nr*tan( pi/n ) = P(A_n) / cos(pi/n)
 
 And for a 2n polygon: 
 
            P(A_2n) = 4nr*sin(pi/2n)        P(B_2n) = 4nr*tan(pi/2n) = P(A_2n) / cos(pi/2n)
 

 Now we need to keep P(A_2n) and P(B_2n) in fucntion of P(A_n) and P(B_n).

			(a bit veery heavy math)  
 
 The result:

           P(B_2n) = 2 * P(A_n) * P(B_n) / ( P(A_n) + P(B_n) )
           P(A_2n) = sqrt(P(A_n) * P(B_2n))
 
 Since A approaches the perimeter of the circle from smaller values ​​and B from larger values, we can use these to
 calculate method errors. That is, once we stop at a certain number of sides, we will take the average of both pi's
 calculated with the different perimeters as the value of this, and the difference of these as the error that we are commenting;
 thus we will have the range of values ​​in which the true pi is found.

*/

#include <iostream> 
#include <cmath>	
#include <fstream>

using namespace std;

int main() {
	long n = 2323534245; //Sides number of the polygon
	cout << endl
		 << "  ------------------------------------------------------------------------------------------";
	cout << endl
		 << "                            Sides of the polygon: " << n;
	cout << endl
		 << "  ------------------------------------------------------------------------------------------";
	double radius = 1; 
	double A; //perimeter inscribed square
	double B; // perimeter circunscribed square
	double m = 4; //sides number of the polygons with wich we are working
	A = 4 * sqrt(2) * radius; // Inscribed square P(square) = 4 * side  side = sqrt(r^2 + r^2) = sqrt(2)*r
	B = 8 * radius;	//Circunscribed. r = sid/2 so P = 8r

	while (m * 2 <= n){
		//We calculate the 2n perimeter with the ecuation we got before
		B = 2 * A * B / (A + B);
		A = sqrt(A * B);
		m = m * 2;
	}

	double pi = (A / 2 / radius + B / 2 / radius) / 2;	 //Pi is the mean of the valor of pi with each perimeter
	double err = abs(A / 2 / radius - B / 2 / radius) / 2; //and the error
	cout.precision(15); 
	cout << endl
		 << "  ------------------------------------------------------------------------------------------";
	cout << endl
		 << "                       With a  " << m << " sides polygon, we obtain: ";
	cout << endl
		 << "   ";
	cout << endl
		 << "                          "
		 <<"    Pi = " << pi << "  +/-  " << err;
	cout << endl
		 << "   ";
	cout << endl
		 << "                   "
		 << "               or, pi i between";
	cout << endl
		 << "                        " << pi + err << "   y   " << pi - err;
	cout << endl
		 << "  -----------------------------------------------------------------------------------------" << endl
		 << endl;

	return 0; 
}
