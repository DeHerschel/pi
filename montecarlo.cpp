/*
Montecarlo method to calculate PI. 

Starting from a circle circumscribed in a square, 
PI can be calculated from the proportion between 
random points inside the circle and the total points
in the square.
               points inside the circle
        pi = -----------------------------
    	 	       total points

So there is a square with side R, with center x=0, y=0 and
innside the square is incribed the cirle, with radius R, logically.
We can generate random numbers and verify if they are in the circle
simply with an inequality from the equation of the circle:

		x^2 + y^2 = r^2,
		 _
		|
		|	x^2 + y^2 > r^2		Not in
		|
		|	x^2 + y^2 <= r^2    In
		|_

Since the Montecarlo results are not the same in each execution of the
program (because the random nature of the calculation), we will make 
the code repeat the method a certain number of times to do statistics
withe the diferents results of PI.

We will get the mean and the standard deviation, with wich we will be obtain
an estimation of the error of the method for obtain a reliable pi independent of
the execution.

 */

#include <iostream> 
#include <cmath>	
#include <fstream>

using namespace std;

int main()
{
	double points = 178674533; // NUMBER OF RANDOM POINTS
	cout << endl
		 << "  --------------------------------------------------------------------------------------------";
	cout << endl
		 << "                            points :   " << points;
	cout << endl
		 << "  ------------------------------------------------------------------------------------------";

	double radius = 1;
	srand((unsigned)time(0)); // RANDOM
	double x; 
	double y;

	double inside = 0; // point in the circle
	int repetitions = 10; // repetitiosn of the method
	double pi_array[repetitions]; 

	for (int j = 0; j < repetitions; j++)
	{
		for (int i = 0; i < points; i++)
		{ 
			/* random points (between -r and r)
			x = (-radius) + ((double)rand() / (double)RAND_MAX) * (radius - (-radius));
			y = (-radius) + ((double)rand() / (double)RAND_MAX) * (radius - (-radius));
			*/
			/* random between 0 and r.
			This is like putting points only in a quarter part of the square.
			So, later, calculating pi we need to multiply per 4 the points inside.
			This make the program faster...
			*/
			x = ((double)rand() / (double)RAND_MAX) * radius;
			y = ((double)rand() / (double)RAND_MAX) * radius;
		
			if (x * x + y * y < radius * radius) //inside?
			{
				inside++;
			}
		}
		pi_array[j] = 4 * inside / points; // PI. Quit the 4 if chosing points between -r and r
		inside = 0;

	}

	double pi = 0;
	double error = 0;
	// average of all results
	for (int j = 0; j < repetitions; j++)
	{
		pi = pi_array[j] / repetitions + pi;
	}
	// standard deviation
	for (int j = 0; j < repetitions; j++)
	{
		error = error + pow(pi - pi_array[j], 2) / repetitions;
	}
	error = sqrt(error);


	cout.precision(15); // digits to display

	cout << endl
		 << "  ------------------------------------------------------------------------------";
	cout << endl
		 << "                          "
		 << "Pi = " << pi << "  +/-  " << error;
	cout << endl
		 << "   ";
	cout << endl
		 << "                   "
		 << "o, dicho de otra manera, el valor de pi se encuentra entre";
	cout << endl
		 << "                          " << pi + error << "   y   " << pi - error;
	cout << endl
		 << "  ---------------------------------------------------------------------------" << endl
		 << endl;

	return 0; 
}

