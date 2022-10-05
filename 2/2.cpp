#include <iostream>;
#include <cmath>;

using namespace std;


int main() {
	float x = 0;
	float y = 0;
	float z = 0;
	float f = 0;
	cout << "Enter x,y,z:";
	cin >> x>> y>> z;
	f = (x * y * z - 3.3 * abs(x + pow(y, 1 / 4))/ (pow(10, 7) + pow(log(4), 1 / 4)));

	cout << f;
}