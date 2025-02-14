#include <iostream>
#include <algorithm>
using namespace std;

int minimum = 100000;
int ans;


int check(int A[], int x[], int n) {
	int sumLeft = 0;
	int sumRight = 0;
	
	for(int i = 1;i<=n;i++){
		if(x[i] == 0){
			sumLeft += A[i-1];
		}
		else{
			sumRight += A[i-1];
		}
	}
	
	int combine = abs(sumLeft - sumRight);
	
	if(combine < minimum){
		minimum = combine;
		for(int i = 1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	
	return minimum;
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
6
12 20 19 45 2 30

7
4 12 13 29 31 32 50
*/
