#include <iostream>
using namespace std;

void print_sol(int x[], int n) {
    // Print the current subset solution
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void subset2(int x[], int l, int n) {
    // Print the subset for the current level
    print_sol(x, l);

    int j;
    if (l == 0)
        j = 1;
    else
        j = x[l] + 1;

    // Generate next elements for the subset
    for (int i = j; i <= n; i++) {
        x[l + 1] = i;
        subset2(x, l + 1, n);
    }
}

int main() {
    int n;
	cin>> n; // Number of elements
    int x[n + 1]; // Array to store subset (size n+1 to use indices starting from 1)

    subset2(x, 0, n); // Start the subset generation

    return 0;
}

