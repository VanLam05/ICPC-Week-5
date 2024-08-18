#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    double P, S = 0;

    if (k == 1) {
        sort(D.begin(), D.end());
        P = D[N / 2];
    } else if (k == 2) {
        P = 0;
        for (int i = 0; i < N; i++) {
            P += D[i];
        }
        P /= N;
    }

    for (int i = 0; i < N; i++) {
        S += pow(abs(D[i] - P), k);
    }

    cout << fixed << setprecision(2) << S << endl;

    return 0;
}
