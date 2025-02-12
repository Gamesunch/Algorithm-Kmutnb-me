#include <iostream>

using namespace std;

int ct = 0;

void backtrack(int x[], int pos, int n, int k, int bulb) {
    if (pos > n) {
        if (bulb == k) {
            ct++;
            for (int i = 1; i <= n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    
    // Choose 1
    x[pos] = 1;
    backtrack(x, pos + 1, n, k, bulb + 1);
    
    // Choose 0
    x[pos] = 0;
    backtrack(x, pos + 1, n, k, bulb);
}

int main() {
    int n, k;
    cin >> n >> k;
    int x[n + 1];
    
    backtrack(x, 1, n, k, 0);
    
    cout << ct;
    
    return 0;
}

