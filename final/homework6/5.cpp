#include <iostream>
using namespace std;

int maxvalue = -10000;
int ans;


int check(int A[],int x[], int n) {
	int sumA = 0;
	
    for (int i = 1; i < n; i++) {
    	if(x[i] != x[i+1]){
    		sumA += A[i-1]*x[i];
		}
    }

    if(sumA > maxvalue){
    	maxvalue = sumA;
	}
	
	return maxvalue;
}

void subset1(int A[],int x[], int l, int r) {
    if (l == r) {
        ans = check(A, x, r);
		
    } else {
        x[l + 1] = 1;
        subset1(A, x, l + 1, r);
        x[l + 1] = 0;
        subset1(A, x, l + 1, r);
    }
}

int main() {
    int n;
	cin>>n;
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
    int x[n + 1];

    subset1(A, x, 0, n);
    cout<<ans;
	

    return 0;
}

/*

input
10
30 10 8 20 11 12 25 13 20 19
output
95

*/
