#include <iostream>
using namespace std;

int check(int A[],int x[], int n,int k) {
	int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i-1]*x[i];
    }
    
    if(sum == k){
        for(int i = 1;i<=n;i++){
        	if(A[i-1]*x[i] != 0){
        		cout<<A[i-1]*x[i]<<" ";
			}
		}
		cout<<endl;
	}
	
	return sum;
}

void subset1(int A[],int x[], int l, int r,int k) {
    if (l == r) {
        int sum = check(A,x,r,k);
    } else {
        x[l + 1] = 1;
        subset1(A, x, l + 1, r, k);
        x[l + 1] = 0;
        subset1(A, x, l + 1, r, k);
    }
}

int main() {
    int n,k;
    
	
	cin>>n>>k;
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
    int x[n + 1];        // Array to store subset

    subset1(A,x, 0, n, k);

    return 0;
}

/*

5 12
25 10 9 2 1 

*/
