#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << ceil((A+C)/3) + ceil((B+D)/3);
    return 0;
}