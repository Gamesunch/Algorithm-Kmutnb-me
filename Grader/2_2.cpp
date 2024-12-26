#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	
	vector<int> A(n);
	
	for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
	
	sort(A.begin(),A.end());
	
	int min = 1000000;
	int left = 0;
	int right = n-1;
	
	while(left <= right){
		int sum = A[left] + A[right];
		if(sum == k){
			if(abs(A[left] - A[right]) < min ){
				min = abs(A[left] - A[right]);
			}
			left++;
			right--;
		}
		else if(sum < k){
			left++;
		}
		else{
			right--;
		}
	}
	
	cout<<min;
	
	return 0;
	
}	
