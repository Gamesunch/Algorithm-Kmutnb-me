#include <iostream>

using namespace std;

int ct = 0;

void print_sol(int x[], int n,int k) {
	int bulb = 0;
	
	for(int i = 1;i<=n;i++){
		bulb += x[i];
	}
	
	if(bulb == k){
		ct++;
	}
}

void subset1(int x[], int l, int r,int k) {
    if (l == r) {
        print_sol(x, r,k);
    } else {
        x[l + 1] = 1;
        subset1(x, l + 1, r,k);
        x[l + 1] = 0;
        subset1(x, l + 1, r,k);
    }
}

int main() {
    int n,k;
	cin>>n>>k;            // Number of elements
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n, k);
    
    cout<<ct;

    return 0;
}
