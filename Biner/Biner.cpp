#include <iostream>

using namespace std;

unsigned long long formula(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return formula(n - 1, k - 1) * n / k;
}

unsigned long long Xi(unsigned long long N, int count, int position) {
    if (count == 0) {
        return 0;
    }
    if (formula(position - 1, count) >= N) {
        return Xi(N, count, position - 1);
    } else {
        return (1ULL << (position - 1)) | Xi(N - formula(position - 1, count), count - 1, position - 1);
    }
}

int main() {
    unsigned long long N;
    cin >> N;
    cout << Xi(N,30,64);
    
    return 0;
}
