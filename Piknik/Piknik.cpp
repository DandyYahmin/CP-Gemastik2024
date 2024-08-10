#include <iostream>
using namespace std;

int main() {
    
    int N, M;
    cin >> N >> M;

    if (N<=2 || N>=100) return 0;
    if (M<=0 || M>=N*(N-1)/2) return 0;

    int baris = M+1, kolom = baris*2;

    int penumpang[baris][kolom] = {};
    
    penumpang[0][0] = N;
    penumpang[0][1] = M;

    for (int i=1; i<baris; i++) {
        cin >> penumpang[i][0] >> penumpang[i][1];
    }

    for (int i=0; i<baris; i++) {
        if (penumpang[i][0] == penumpang[i + 1][0] || penumpang[i][0] == penumpang[i + 1][1] ||
            penumpang[i][1] == penumpang[i + 1][0] || penumpang[i][1] == penumpang[i + 1][1]) {
            penumpang[i+1][i+2] = penumpang[i][0];
            penumpang[i+1][i+3] = penumpang[i][1];
            penumpang[i][0] = 0;
            penumpang[i][1] = 0;
        }
    }

    int bus = 0;

    for (int i=0; i<baris; i++) {
        if(i == M) {
            if(penumpang[i][0] != penumpang[0][0] && penumpang[i][1] != penumpang[0][1] && penumpang[i][0] != penumpang[0][1] && penumpang[i][1] != penumpang[0][0]) {
                bus++;
            }
        }else if(penumpang[i][0] != 0){
            bus++;
        }
    }

    cout << bus;

    return 0;
}