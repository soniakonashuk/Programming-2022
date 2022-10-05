#include <iostream>;
using namespace std;

void main() {
	long int k = 0;
	cout << "Enter k-natural number" << "\n";
	cin >> k;
	int h = 0;
	float m = 0;
	double ostacha = 0;
	
	m = k / 60;

	if (k%3600 == 0) {
		h = k / 3600;
		cout << "h:" << h << '\n';
		cout << "m:" << 0;
	}

	else {
		ostacha = k % 3600;
		m = ostacha / 60;
		h = k / 3600;
		cout << "h:" << h << '\n';
		cout << "m:" << m;
	}
	
}