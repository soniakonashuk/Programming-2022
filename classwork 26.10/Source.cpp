#include <iostream>
using namespace std;
#include <math.h>


int main() {
	int a[10] = { 1,6,5,9,4,9,7,3,9,0 };
	int sum = 1;
	for (int i = 0; i < 9; i++) {
		sum *= a[i];
		

	}
	cout << pow(sum, 1 / 9.0);
	return 0;
	}