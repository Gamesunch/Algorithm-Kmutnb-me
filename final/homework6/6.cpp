#include <iostream>
#include <algorithm>
using namespace std;

int maxvalue = -10000;
int Book[10000];
int Check[10000];
bool flag = false;
int ans;


void check(int A[],int x[], int n, int k) {
	int sumA = 0;
	
	for (int i = 0; i < 10000; i++) {
        Check[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
    	sumA += A[i-1]*x[i];
    	if(x[i] == 1){
    		Check[A[i-1]] += 1;
		}
    }

    if(sumA <= k && sumA > maxvalue){
    	maxvalue = sumA;
    	int c = 0;
    	for(int i = 1;i<=n;i++){
	    	if(Check[A[i-1]] == 1){
	    		Book[c] = A[i-1];
	    		c++;
	    		flag = true;
			}
		}
			
	}
}

void subset1(int A[],int x[], int l, int r, int k) {
    if (l == r) {
        check(A, x, r, k);
		
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
	
    int x[n + 1];

    subset1(A, x, 0, n, k);
    
    sort(Book,Book+3);
    if(flag){
    	for(int i = 0;i<n;i++){
	    	if(Book[i] != 0){
	    		cout<<Book[i]<<endl;
			}
		}
	}
	else{
		for(int i = 0;i<3;i++){
			cout<<0<<endl;
		}
	}
	
    return 0;
}

/*

input
8 600
136
411
211
200
275
189
232
375

output
136
189
275

*/
