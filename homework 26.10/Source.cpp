
#include <iostream>
#include <math.h>
using namespace std;
double S(double x){
	return -log(2) - cos(2)-cos(4*x)/2 - cos(6*x)/3 -cos (8*x)/4 - cos(10*x)/5;
}
double Y(double x) {
	return log(abs(sin(x)));
}

int main() {
	double s;
	double x=1;
	double y;
	double h = 0.5;
	double a = 2;
	double P;
	for (int i = 0; i < 10; i++) {
		x = a + i * h;
		y = Y(x);
		s = S(x);
		P = abs((s - y) / y) * 100;
		cout << x << " " << s << " " << y << " " << P << endl;
	}
}
