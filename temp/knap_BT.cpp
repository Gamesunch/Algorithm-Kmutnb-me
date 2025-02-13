#include <iostream>
using namespace std;

int ct = 0;
int maxvalue = -10000;
int maxweight = -10000;
int Amax[1000];


int check(int A[],int B[],int x[], int n,int k) {
	ct++;
	
	int sumA = 0;
	int sumB = 0;
	
	
    for (int i = 1; i <= n; i++) {
        sumA += A[i-1]*x[i];
        sumB += B[i-1]*x[i];
    }

    if(sumA <= k){
        if(sumB > maxvalue){
        	maxvalue = sumB;
        	maxweight = sumA;
        	for(int j = 1;j<=n;j++){
        		Amax[j-1] = x[j];
			}
		}
	}
	
	return maxvalue;
}

void subset1(int A[],int B[],int x[], int l, int r,int k,int total) {
    
    if(total <= k){
    	check(A, B, x, r, k);
	}
	
    if (l == r) {
        return;
		
    }
    if(total > k){
    	return;
	}
	
	x[l + 1] = 1;
	total += A[l];
    subset1(A, B, x, l + 1, r, k, total);
    x[l + 1] = 0;
    total -= A[l];
    subset1(A, B, x, l + 1, r, k, total);
}

int main() {
    int n,k;
    
	
	cin>>n>>k;
	int A[n];
	int B[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	for(int i = 0;i<n;i++){
		cin>>B[i];
	}
	
	
    int x[n + 1];

    subset1(A, B, x, 0, n, k, 0);
    
    for(int i = 0;i<n;i++){
		cout<<Amax[i]<<" ";
	}
	cout<<endl;
	
    cout<<maxweight<<" "<<maxvalue<<endl;
    
    cout<<ct<<endl;

    return 0;
}

/*

4 18
12 5 4 2
8 7 4 2

*/
