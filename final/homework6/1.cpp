#include <iostream>
#include <algorithm>
using namespace std;

void permute(char X[], int start, int end) {
    if (start == end) {
        for (int i = 1; i <= end; i++) {
            cout << X[i];
        }
        cout <<endl;
        return;
    }

    for (int i = start; i <= end; i++) {
       
        if (i != start && X[i] == X[start]) continue;

        swap(X[start], X[i]);
        sort(X + start + 1, X + end + 1);
        permute(X, start + 1, end);
        swap(X[start], X[i]);
    }
}

int main() {
    int n;
    cin >> n;
    char X[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }

    sort(X + 1, X + n + 1);  // Sort input first for correct order
    permute(X, 1, n);

    return 0;
}
/*
3
A B C

4
E X A B
*/
