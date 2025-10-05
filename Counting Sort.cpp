#include <iostream>
using namespace std;

int main() {
    int A[] = {4, 2, 1, 3, 2, 4, 1};
    int n = 7;
    int k = 4;

    int C[5];
    int B[7];

    for (int i = 1; i <= k; i++) {
        C[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    for (int i = 2; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}

