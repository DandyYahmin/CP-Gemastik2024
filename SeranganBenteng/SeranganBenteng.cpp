#include <iostream>
#include <vector>

using namespace std;

unsigned long long hitungKoin(unsigned long long tentara, unsigned long long P, unsigned long long Q) {
    if (tentara == 0) return 0;

    vector<unsigned long long> koin(tentara + 1, 1e18);
    koin[tentara] = 0;

    vector<unsigned long long> jumlah;
    jumlah.push_back(tentara);

    int awal = 0;
    
    while (awal < jumlah.size()) {
        unsigned long long current = jumlah[awal++];
        unsigned long long current_koin = koin[current];

        if (current > 0 && koin[current - 1] > current_koin + 1) {
            koin[current - 1] = current_koin + 1;
            jumlah.push_back(current - 1);
        }

        if (current % 2 == 0) {
            unsigned long long next = current / 2;
            if (koin[next] > current_koin + P) {
                koin[next] = current_koin + P;
                jumlah.push_back(next);
            }
        }

        if (current % 3 == 0) {
            unsigned long long next = current / 3;
            if (koin[next] > current_koin + Q) {
                koin[next] = current_koin + Q;
                jumlah.push_back(next);
            }
        }
    }

    return koin[0];
}

int main() {
    unsigned long long P, Q, N;
    cin >> N >> P >> Q;

    unsigned long long A[N] = {};

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cout << hitungKoin(A[i], P, Q) << endl;
    }

    return 0;
}
