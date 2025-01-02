#include <iostream>
#include <vector>
using namespace std;

// Function to perform Distribution Counting
void DistributionCounting(int A[], int n, int l, int u) {
    int range = u - l + 1; // Calculate the range of values
    int* D = new int[range](); // Frequency array, initialized to 0
    int* S = new int[n];       // Sorted array

    // Step 1: Initialize frequencies
    for (int j = 0; j < range; j++) {
        D[j] = 0;
    }

    // Step 2: Compute frequencies
    for (int i = 0; i < n; i++) {
        D[A[i] - l] += 1;
    }

    // Step 3: Accumulate frequencies for distribution
    for (int j = 1; j < range; j++) {
        D[j] += D[j - 1];
    }

    // Step 4: Place elements into the sorted array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        int j = A[i] - l;
        S[D[j] - 1] = A[i];
        D[j] -= 1;
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;

    // Clean up dynamic memory
    delete[] D;
    delete[] S;
}

// Driver code
int main() {
    int A[] = {16,25,2,54,36,9,12,66};
    int n = sizeof(A) / sizeof(A[0]);
    int Min = 2; // Minimum value in the range
    int Max = 66; // Maximum value in the range

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Perform Distribution Counting
    DistributionCounting(A, n, Min, Max);

    return 0;
}
