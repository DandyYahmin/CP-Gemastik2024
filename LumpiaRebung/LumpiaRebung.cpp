#include <iostream>
using namespace std;

int main() {
    int N;
    int L;
    cin >> N >> L;

    int B[N];
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int bagian[N+1];
    int ukuran = 1;
    bagian[0] = L;

    for (int i = 0; i < N; ++i) {
        int bagianTerpotong = B[i] - 1;
        int panjangTerpotong = bagian[bagianTerpotong];
        int updatePanjang = panjangTerpotong / 2;

        for (int j = ukuran; j > bagianTerpotong + 1; --j) {
            bagian[j] = bagian[j - 1];
        }

        bagian[bagianTerpotong] = updatePanjang;
        bagian[bagianTerpotong + 1] = updatePanjang;
        ukuran++;
    }

    for (int i = 0; i < ukuran; ++i) {
        cout << bagian[i] << " ";
    }

    return 0;
}