#include <iostream>

using namespace std;

int Compute(int A[],int l,int m,int r){
	
	int LeftMax = -10000;
	int sum = 0;
	for(int i = m;i>=l;i--){
		sum += A[i];
		if(sum > LeftMax){
			LeftMax = sum;
		}
	}
	
	int RightMax = -10000;
	sum = 0;
	for(int i = m+1;i<=r;i++){
		sum += A[i];
		if(sum > RightMax){
			RightMax = sum;
		}
	}
	
	return RightMax + LeftMax;
}

int MaximumSubArray(int A[],int l,int r){
	if(l == r){
		return A[l];
	}
	
	int m = l+(r-l)/2;
	
	int LeftSum = MaximumSubArray(A,l,m);
	int RightSum = MaximumSubArray(A,m+1,r);
	int Combine = Compute(A,l,m,r);
	
	if(LeftSum >= RightSum && LeftSum >= Combine){
		return LeftSum;
	}
	else if(RightSum >= LeftSum && RightSum >= Combine){
		return RightSum;
	}
	else{
		return Combine;
	}
}

int main(){
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	cout<<MaximumSubArray(A,0,n-1);
	
}
