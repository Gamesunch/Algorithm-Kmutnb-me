#include <iostream>
using namespace std;

int find_first(int A[],int size,int target){
	int low = 0;
	int high = size - 1;
	int res = -1;
	
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(A[mid] == target){
			res = mid;
			high = mid - 1;
		}
		else if(A[mid] < target){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return res;
}

int find_last(int A[],int size,int target){
	int low = 0;
	int high = size - 1;
	int res = -1;
	
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(A[mid] == target){
			res = mid;
			low = mid + 1;
		}
		else if(A[mid] < target){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return res;
}

int finddupe(int A[],int size,int target){
	int first = find_first(A,size,target);
	if(first == -1){
		return -1;
	}
	
	int last = find_last(A,size,target);
	return last-first + 1;
}

int main(){
	int n,k;
	
	cin>>n>>k;
	
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	cout<<finddupe(A,n,k);
}
