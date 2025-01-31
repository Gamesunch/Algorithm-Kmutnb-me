#include <iostream>
using namespace std;

void print_sol(int A[],int x[], int n,int k) {
	
	int sum = 0;
	
    for (int i = 1; i <= n; i++) {
    	sum += A[x[i]-1];
    }
    
    if(sum == k){
    	for (int i = 1; i <= n; i++) {
        	cout<<x[i]<<" ";
    	}
    	cout<<endl;
	}
    
}

void subset2(int A[],int x[], int l, int n,int k) {

    print_sol(A,x, l,k);

       int j;
    if (l == 0) 
	j = 1; 
    else 
        j = x[l] + 1;

    for (int i = j; i <= n; i++) {
        x[l + 1] = i;
        subset2(A,x, l + 1, n,k);
    }
}

int main() {
    int n,k;
    
	
	cin>>n>>k;
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
    int x[n + 1];

   subset2(A,x, 0, n, k);

    return 0;
}

/*

5 12
25 10 9 2 1 

*/
