#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* a = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    int gema = 0;
    for (int i = 0; i < N - 1; ++i) {
        int jarak = a[i + 1] - a[i];
        if (jarak > gema) {
            gema = jarak;
        }
    }

    cout << gema << endl;
    cout << a[N - 1] - a[0] << endl;

    return 0;
}
