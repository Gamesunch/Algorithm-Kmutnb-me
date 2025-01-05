#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void intersection(int A[], int B[], int n, int maxValue) {
    
    
    vector<int> freqA(maxValue + 1, 0);
    vector<int> freqB(maxValue + 1, 0);

    
    for (int i = 0; i < n; i++) {
        freqA[A[i]]++;
    }

    
    for (int i = 0; i < n; i++) {
        freqB[B[i]]++;
    }

    
    for (int i = 0; i < n; i++) {
        if (freqB[A[i]] > 0) {
            cout << A[i] << " ";
            freqB[A[i]] = 0;
        }
    }
    cout << endl;
}

void Union(int A[], int B[], int n, int maxValue) {
    
    vector<int> freq(maxValue + 1, 0);

    
    for (int i = 0; i < n; i++) {
        if (freq[A[i]] == 0) {
            cout << A[i] << " ";
            freq[A[i]]++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (freq[B[i]] == 0) {
            cout << B[i] << " ";
            freq[B[i]]++;
        }
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int A[n], B[n];
    int maxValue = 0;

    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        maxValue = max(maxValue, A[i]);
    }

    
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        maxValue = max(maxValue, B[i]);
    }

    intersection(A, B, n, maxValue);
    Union(A, B, n, maxValue);

    return 0;
}

