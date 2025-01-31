#include <iostream>

using namespace std;

int Partition(int A[],int l,int r){
	int m = l+(r-l)/2;
	
	if(A[m] < A[l]){
		swap(A[m],A[l]);
	}
	if(A[r] < A[l]){
		swap(A[l],A[r]);
	}
	if(A[m] < A[r]){
		swap(A[m],A[r]);
	}
	
	int p = A[r];
	int i = l-1;
	int j = r;
	
	while(i < j){
		do{
			i++;
		}while(A[i] < p);
		
		do{
			j--;
		}while(A[j] > p);
		
		if(i >= j) break;
		
		swap(A[i],A[j]);
	}
	swap(A[i],A[r]);
	
	return i;
	
}

void Quicksort(int A[],int l,int r){
	if(l<=r){
		int p = Partition(A,l,r);
		cout<<p+1<<" ";
		
		Quicksort(A,l,p-1);
		Quicksort(A,p+1,r);
	}
}

int main(){
	int n;
	cin>>n;
	
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	Quicksort(A,0,n-1);
	cout<<endl;
	
	for(int i = 0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	
}
