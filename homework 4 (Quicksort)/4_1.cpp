#include <iostream>
using namespace std;

//pivot start at first elements
int Partition(int A[], int l, int r) {
    int pivot = A[l]; 
    int i = l, j = r + 1;

    while (true) {
        do {
            i++;
        } while (A[i] >= pivot);

        do {
            j--;
        } while (A[j] < pivot);
		
	swap(A[i], A[j]);
		
        if (i >= j) break;
        
    }
    swap(A[i], A[j]);	
    swap(A[l], A[j]);

    return j;
}

void Quicksort(int A[], int l, int r) {
    if (l < r) {
        
        int s = Partition(A, l, r);

        Quicksort(A, l, s - 1);
        Quicksort(A, s + 1, r);
    }
}

int main() {
    int A[] = {16,25,2,54,36,9,12,66};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    Quicksort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
