#include <iostream>
using namespace std;

int ct = 0;

int check(int A[],int x[], int n,int k) {
    for(int i = 1;i<=n;i++){
        if(A[i-1]*x[i] != 0){
        	cout<<A[i-1]*x[i]<<" ";
		}
	}
	cout<<endl;
		
}

void subset1(int A[],int x[], int l, int r,int k,int total) {
	
    if (total == k) {
        check(A,x,r,k);
    }
	
	if (l == r){
		ct++;
		return;
	}
	
	if(total > k){
		ct++;
		return;
	}
	
	x[l + 1] = 1;
	total += A[l];
   	subset1(A, x, l + 1, r, k, total);
   	
   	x[l + 1] = 0;
   	total -= A[l];
   	subset1(A, x, l + 1, r, k, total);
	
   	
}

int main() {
    int n,k;
    
	
	cin>>n>>k;
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
    int x[n + 1];        // Array to store subset

    subset1(A,x, 0, n, k,0);
    cout<<ct<<endl;

    return 0;
}

/*

4 12
25 10 9 2 

*/
