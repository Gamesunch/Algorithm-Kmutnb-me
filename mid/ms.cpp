#include <iostream>

using namespace std;

void Merge(int A[],int l,int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1];
	int R[n2];
	
	for(int i = 0;i<n1;i++){
		L[i] = A[l + i];
	}
	
	for(int i = 0;i<n2;i++){
		R[i] = A[m + i + 1];
	}
	
	int i = 0;
	int j = 0;
	int k = l;
	
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		A[k] = L[i];
		i++;
		k++;
	}
	
	while(j < n2){
		A[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int A[],int l,int r){
	if(l<r){
		int m = l+(r-l)/2;
		MergeSort(A,l,m);
		MergeSort(A,m+1,r);
		Merge(A,l,m,r);
	}
}

int main(){
	int n;
	cin>>n;
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	for(int i = 0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	MergeSort(A,0,n-1);
	
	for(int i = 0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
