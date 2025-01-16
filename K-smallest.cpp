#include <iostream>
#include <vector>
using namespace std;

vector<int> arr = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4;
int n = arr.size();

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int l, int r) {
    int mid = (l + r) / 2;

    // Median of three logic
    if (arr[mid] < arr[l])
        swap(arr[mid], arr[l]);
        
    if (arr[r] < arr[l])
        swap(arr[r], arr[l]);
        
    if (arr[mid] < arr[r])
        swap(arr[mid], arr[r]);

    int pivot = arr[r];
    int i = l - 1;
    int j = r;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    swap(arr[i], arr[r]);
    return i;
}

int quickSelect(int low, int high, int k) {
    int p = partition(low, high);
    
    if(low == high){
    	return arr[low];
	}

    if (p == k - 1) {
        return arr[p];
    } else if (p > k - 1) {
        return quickSelect(low, p - 1, k);
    } else {
        return quickSelect(p + 1, high, k);
    }
}

int main() {
    cout<< quickSelect(0, n - 1, k) << endl;
    return 0;
}

