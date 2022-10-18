#include <iostream>;

using namespace std;

void main() {
	int a[] = { 1, -3, 2, -3, -4, 1, -5 };
	int N = sizeof(a) / sizeof(a[0]); // calculate length of the array
	int max = a[0];

	for (int i = 0; i < N; i++) {
		int kvadrat = a[i] * a[i];
		if (kvadrat > max) {
			max = kvadrat;
		}
	}

	cout << max;
}