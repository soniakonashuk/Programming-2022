// Обчислити значення функції y=4x^3 - 2x^2 + 5  для значень  , які змінюються від -3 до 1, з кроком 0.1.

#include <iostream>;
#include <cmath>;
using namespace std;

double f(double x) {
	return 4 * pow(x, 3) - 2 * pow(x, 2) + 5;
}

int main() {
	for (double x = -3; x < 1.1; x+= 0.1) {
		cout << x << " " << f(x) << endl;
	}
	

	return 0;
}
