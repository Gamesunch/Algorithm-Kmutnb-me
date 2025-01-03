#include <iostream>

using namespace std;

int ComputeSum(int arr[],int l,int m ,int r){
	int leftmax = -1000000;
	int sum = 0;
	for(int i = m;i >= l;i--){
		sum += arr[i];
		if(sum > leftmax){
			leftmax = sum;
		}
	}
	
	int rightmax = -1000000;
	sum = 0;
	for(int i = m+1;i <= r;i++){
		sum += arr[i];
		if(sum > rightmax){
			rightmax = sum;
		}
	}
	
	return (leftmax + rightmax);
}

int MaximumSubarray(int arr[],int l,int r){
	if(l == r){
		return arr[l];
	}
	
	int m = (l+r)/2;
	
	int leftsum = MaximumSubarray(arr,l,m);
	int rightsum = MaximumSubarray(arr,m+1,r);
	int combine = ComputeSum(arr,l,m,r);
	
	if(leftsum >= rightsum && leftsum >= combine){
		return leftsum;
	}
	else if(rightsum >= leftsum && rightsum >= combine){
		return rightsum;
	}
	else{
		return combine;
	}
	
	
	
}


int main(){
	int A[8] = {-5,2,4,-3,6,-1,7,2};
	
	cout<<MaximumSubarray(A,0,8-1);
}
