#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;  

    int A[N] = {}, X[Q] = {};

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < Q; i++) {
        cin >> X[i];
    }

    for (int i=0; i < N-1; i++) {
        for (int j=0; j < N-i-1; j++) {
            if (A[j] < A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    for (int i =0; i < Q; i++) {
        int total = 0;
        for (int j=0; j < N; j+=X[i]) {
            for (int k=0; k < X[i]; k++) {
                if (j+k >= N) {
                    break;
                }
                if (k == X[i]-1) {
                    total += (A[j+k]-(A[j+k]/2));
                }else {
                    total += A[j+k];
                }
            }
        }
        cout << total << endl;
    }

    return 0;
}