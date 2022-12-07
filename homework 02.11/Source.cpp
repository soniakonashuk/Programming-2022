#include <iostream>
#include <math.h>
using namespace std;
double M1(double a, double b, double c) {
	return 0.5 * sqrt(2.0* pow(b,2) + 2.0 *pow(c,2) - pow (a,2));
}
double M2(double a, double b, double c) {
	return 0.5 * sqrt(2.0 * pow(a,2) + 2.0 * pow(b,2) - pow(c,2));
}
double M3(double a, double b, double c) {
	return 0.5 * sqrt(2.0 * pow(c,2) + 2.0 * pow(a,2) - pow(b,2));
}
double M1new(double z, double m, double k) {
	return 0.5 * sqrt(2.0 * pow(m, 2) + 2.0 * pow(k, 2) - pow(z, 2));
}
double M2new(double z, double m, double k) {
	return 0.5 * sqrt(2.0 * pow(z, 2) + 2.0 * pow(m, 2) - pow(k, 2));
}
double M3new(double z, double m, double k) {
	return 0.5 * sqrt(2.0 * pow(k, 2) + 2.0 * pow(z, 2) - pow(m, 2));
}
int main() {
	double a = 5;
	double b = 10;
	double c = 15;
	double mediana1 = M1(a, b, c);
	double mediana2 = M2(a, b, c);
	double mediana3 = M3(a, b, c);
	cout << mediana1 << " " << mediana2 << " " << mediana3 << endl;
	double z = mediana1 = M1(a, b, c);
	double m = mediana2 = M3(a, b, c);
	double k = mediana3 = M3(a, b, c);
	double mediana1new = M1new(z, m, k);
	double mediana2new = M2new(z, m, k);
	double mediana3new = M3new(z, m, k);
	cout << mediana1new << " " << mediana2new << " " << mediana3new;
}
