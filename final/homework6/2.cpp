#include <iostream>
#include <algorithm>
using namespace std;

void permute(int X[], int k, int depth, int n) {
    if (depth == k) {
        for (int i = 0; i < k; i++) {
            cout << X[i];
            if (i < k - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        bool used = false;
        for (int j = 0; j < depth; j++) {
            if (X[j] == i) {
                used = true;
                break;
            }
        }
        if (!used) {
            X[depth] = i;
            permute(X, k, depth + 1, n);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int X[k];

    permute(X, k, 0, n);

    return 0;
}

