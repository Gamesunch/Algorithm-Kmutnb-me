#include <iostream>
#include <algorithm>
using namespace std;

int minimum = 100000;
int ans;


int check(int A[],int B[], int x[], int n) {
	int sumA = 0;
	int sumB = 0;
	
	for(int i = 1;i<=n;i++){
		if(x[i] == 1){
			sumA += B[i-1];
			sumB += A[i-1];
		}
		else{
			sumA += A[i-1];
			sumB += B[i-1];
		}
	}
	
	int combine = abs(sumA - sumB);
	
	if(combine < minimum){
		minimum = combine;
	}
	
	return minimum;
}

void subset1(int A[],int B[],int x[], int l, int r) {
    if (l == r) {
        ans = check(A, B, x, r);
		
    } else {
        x[l + 1] = 1;
        subset1(A, B, x, l + 1, r);
        x[l + 1] = 0;
        subset1(A, B, x, l + 1, r);
    }
}

int main() {
    int n,k;
	cin>>n;
	int A[n];
	int B[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i]>>B[i];
	}
	
    int x[n + 1];

    subset1(A, B, x, 0, n);
    
    cout<<ans;
    
    return 0;
}

/*
4
3 5
7 11
8 8
2 9
*/
