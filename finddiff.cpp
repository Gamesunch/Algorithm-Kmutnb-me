#include <iostream>

using namespace std;

int finddiff(int arr[],int l,int r){
	
	if(l == r){
		return l+1;
	}
	
	int m = (l+r)/2;
	
	int leftSum = 0;
	int rightSum = 0;
	
	for(int i = l;i<=m;i++){
		leftSum += arr[i];
	}
	
	for(int i = m+1;i<=r;i++){
		rightSum += arr[i];
	}
	
	if(leftSum < rightSum){
		return finddiff(arr,m+1,r);
	}
	else if(leftSum > rightSum){
		return finddiff(arr,l,m);
	}
}

int main(){
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	cout<<finddiff(A,0,n-1);
	return 0;
}

/*
8
2 2 2 2 2 3 2 2

8
1 1 2 1 1 1 1 1
*/
