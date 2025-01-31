#include <iostream>
using namespace std;

int A[10000][2];
int Status[10000];

void merge(int l,int m,int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int L[n1][2];
	int R[n2][2];
	
	for(int i = 0;i<n1;i++){
		L[i][0] = A[l + i][0];
		L[i][1] = A[l + i][1];
	}
	
	for(int i = 0;i<n2;i++){
		R[i][0] = A[m+i+1][0];
		R[i][1] = A[m+i+1][1];
	}
	
	
	int i = 0;
	int j = 0;
	int k = l;
	
	while(i < n1 && j < n2){
		if(L[i][0] <= R[j][0]){
			A[k][0] = L[i][0];
			A[k][1] = L[i][1];
			i++;
		}
		else{
			A[k][0] = R[j][0];
			A[k][1] = R[j][1];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		A[k][0] = L[i][0];
		A[k][1] = L[i][1];
		i++;
		k++;
	}
	
	while(j < n2){
		A[k][0] = R[j][0];
		A[k][1] = R[j][1];
		j++;
		k++;
	}
}

void mergeSort(int l,int r){
	if(l < r){
		int m = l+(r-l)/2;
		
		mergeSort(l,m);
		mergeSort(m+1,r);
		merge(l,m,r);
	}
}

void conq(int l,int m,int r){
	int k;
	
	for(int i = m+1;i<=r;i++){ //find first in right
		if(Status[i] == 1){
			k = i;
			break;
		}
	}
	
	for(int i = l;i<=m;i++){
		if(Status[i] == 1 && A[i][1] < A[k][1]){
			Status[i] = 0;
		}
	}
}

void Maxima(int l,int r){
	if(l < r){
		int m = l+(r-l)/2;
		
		Maxima(l,m);
		Maxima(m+1,r);
		conq(l,m,r);
	}
}

int main(){
	int n;
	cin>>n;
	
	for(int i = 0;i<n;i++){
		cin>>A[i][0]>>A[i][1];
	}

	mergeSort(0,n-1);

	for(int i = 0;i<10000;i++){
		Status[i] = 1;
	}
	
	Maxima(0,n-1);
	
	for(int i = 0;i<n;i++){
		if(Status[i] == 1){
			cout<<A[i][0]<<" "<<A[i][1]<<" , ";
		}
	}
	
	return 0;
	
	
}
