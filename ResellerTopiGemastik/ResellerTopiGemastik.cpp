#include <iostream>

using namespace std;

int main() {
    int N, termurah = 1e9, keuntungan = -1;
    cin >> N;
    
    int B[N] = {}, J[N] = {};
    
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    for (int i = 0; i < N; i++) {
        cin >> J[i];
    }

    for (int i = 0; i < N; ++i) {
        if (i >= 2) {
            if (B[i - 2] < termurah) {
                termurah = B[i - 2];
            }
        }
        
        if (i >= 2) {
            int probabilitas = J[i] - termurah;
            if (probabilitas > keuntungan) {
                keuntungan = probabilitas;
            }
        }
    }
    
    if (keuntungan > 0) {
        cout << keuntungan;
    } else {
        cout << "tidak mungkin";
    }
    
    return 0;
}
