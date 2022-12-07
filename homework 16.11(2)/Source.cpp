#include <iostream>

using namespace std;

int main() {
    // lenght of first Array
   const int N = 3;
    double A[N];

    // lenght of second Array
   const int M = 3;
    double B[M];

    // Merged Array
     const int K = M + N;
    double C[K];
    double data;

    for (int i = 0; i < N; i++) {
        cout << "Fill first array with number:";
        cin >> data;
        A[i] = data;
    }

    for (int j = 0; j < M; j++) {
        cout << "Fill second array with number:";
        cin >> data;
        B[j] = data;
    }

    for (int q = 0; q < K; q++) {
        if (q >= N) {
            C[q] = B[q - M];
        }
        else {
            C[q] = A[q];
        }
    }

    for (int i = 0; i < K; i++) {
        cout << C[i] << endl;
    }

    return 0;
}