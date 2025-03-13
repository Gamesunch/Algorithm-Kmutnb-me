#include <iostream>
#include <vector>

using namespace std;

int subset(vector<int> &A, int n, int k) {
    vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        DP[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {

            DP[i][j] = DP[i - 1][j];

            if (A[i - 1] <= j) {
                DP[i][j] |= DP[i - 1][j - A[i - 1]];
            }
        }
    }

    return DP[n][k];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << subset(A, n, k) << endl;

    return 0;
}

