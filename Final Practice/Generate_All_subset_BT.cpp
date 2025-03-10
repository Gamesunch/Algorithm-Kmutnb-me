#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& arr, vector<int>& subset, int index) {
    
    cout << "{ ";
    for (int num : subset) cout << num << " ";
    cout << "}\n";
  
    for (int i = index; i < arr.size(); i++) {
        subset.push_back(arr[i]);
        backtrack(arr, subset, i + 1);
        subset.pop_back();
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> subset;
    backtrack(arr, subset, 0);
    return 0;
}
