#include <iostream>
#include <cmath>
using namespace std;

int ct = 0;
int n = 4;
int x[100];

bool isSafe(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (x[i] == row || abs(x[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

void n_queens(int col) {
    if (col == n) {
        ct++;
        for (int i = 0; i < n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col)) {
            x[col] = row;
            n_queens(col + 1);
        }
    }
}

int main() {
    n_queens(0);
    cout << "Total solutions: " << ct << endl;
    return 0;
}
