

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
class circle {
	public:
		int radius;
		int inside=0;
		circle(int);
		bool isInside(double *);
};
circle::circle(int _radius){
	radius = _radius;
}
bool circle::isInside(double *arr){
	double x = arr[0];
	double y = arr[1];
	if (x * x + y * y < this->radius * this->radius) {
		return true;
	} else {
		return false;
	}
}
class circunscribedSquare{
	public:
		int side;
		int circleradius;
		circunscribedSquare(int);
		double * point();
};
circunscribedSquare::circunscribedSquare(int _radius) {
	side = 2 * _radius;
	circleradius = _radius;
}
double * circunscribedSquare::point() {
	double * pointxy = new double[2];
	pointxy[0] = (0 - this->circleradius) + ((double)rand() / (double)RAND_MAX) * (this->circleradius - (0 - this->circleradius));
	pointxy[1] = (0 - this->circleradius) + ((double)rand() / (double)RAND_MAX) * (this->circleradius - (0 - this->circleradius));
	return pointxy;
}

double average(double array[], int arraylen);
double calError(double n, double array[], int arraylen);
void show(double n, double e);

int main() {
	
	srand((unsigned)time(0)); // RANDOM
	int r = 1;
	double points = 12172223;
	int repetitions = 2;
	double pi_array[repetitions];
	circle circle1 = circle(r);
	circunscribedSquare circunscribed = circunscribedSquare(r);


	for (int j = 0; j < repetitions; j++) {
		for (int i = 0; i < points; i++) {
			double* point = circunscribed.point();
			if (circle1.isInside(point)) {
				circle1.inside++;
			}
		}
		pi_array[j] = 4 * circle1.inside / points;
		circle1.inside = 0;
	}
	double pi = average(pi_array, repetitions);
	double error = calError(pi, pi_array, repetitions);
	show(pi, error);
	return 0;
}
double average(double array[], int arraylen) {
	double avg = 0; 
	for (int j = 0; j < arraylen; j++) {
		avg = array[j] / arraylen + avg;
	}
	return avg;
}
double calError(double n, double array[], int arraylen) {
	double error = 0;
	// standard deviation
	for (int j = 0; j < arraylen; j++){
		error = error + pow(n - array[j], 2) / arraylen;
	}
	error = sqrt(error);
	return error;
}
void show(double pi, double error) {
	cout.precision(15); // digits to display

	cout << endl
		 << "  ------------------------------------------------------------------------------";
	cout << endl
		 << "                          "
		 << "Pi = " << pi << "  +/-  " << error;
	cout << endl
		 << "   ";
	cout << endl
		 << "           "
		 << "or, pi is between";
	cout << endl
		 << "                          " << pi + error << "   and   " << pi - error;
	cout << endl
		 << "  ---------------------------------------------------------------------------" << endl
		 << endl;
}