#include <iostream>
using namespace std;

void findMaxContiguousSum(const int* A, int n) {
    int maxSum = -10000;
    int startIndex = 0, endIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += A[k];
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    
    cout << maxSum << endl;
}

int main() {
    int n;
    
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
    	cin >> arr[i];
	}

    findMaxContiguousSum(arr, n);

    return 0;
}

