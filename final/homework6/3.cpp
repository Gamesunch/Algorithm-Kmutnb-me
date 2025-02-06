#include <iostream>
#include <algorithm>
using namespace std;

void permute(int X[], int k, int start, int depth, int n) {
    if (depth == k) {
        for (int i = 1; i <= k; i++) {
            cout << X[i];
            if (i < k) {
                cout << " ";
            } else {
                cout << "\n";
            }
        }
        return;
    }

    for (int i = start; i <= n; i++) {
        X[depth + 1] = i;
        permute(X, k, i + 1, depth + 1, n);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int X[k + 1];

    permute(X, k, 1, 0, n);

    return 0;
}
