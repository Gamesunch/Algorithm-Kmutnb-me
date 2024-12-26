#include <iostream>

using namespace std;

int interpolationSearch(int arr[],int low,int high, int val){
	int pos;
	
	if(low <= high && val >= arr[low] && val <= arr[high]){
		pos = low + ((high - low) * (val - arr[low])) / (arr[high] - arr[low]);
		
		cout<<pos<<" ";
		
		if(arr[pos] == val){
			return pos;
		}
		
		if(arr[pos] < val){
			return interpolationSearch(arr,pos+1,high, val);
		}
		
		if(arr[pos] > val){
			return interpolationSearch(arr,low, pos-1, val);
		}
	}
	
	return -1;
}

int main(){
	int n,k;
	
	cin>>n>>k;
	
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	interpolationSearch(A,0,n-1,k);
	
	
}
