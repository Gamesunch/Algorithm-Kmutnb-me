#include <iostream>
#include <algorithm>

using namespace std;

void print_sol(int x[], int n) {
    int flag = 0;
    
    for(int j = 1;j<=n;j++){
    	for(int p = 1; p < j;p++){
    		if(abs(p-j) == abs(x[p]-x[j]) || x[j] == x[p]){
    			flag = 1;
			}
		}
	}
	
	if(flag == 0){
		for(int i = 1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
}

void subset1(int x[], int l, int r) {
    if (l == r) {
        print_sol(x, r);
    } else {
    	x[l + 1] = 0;
        subset1(x, l + 1, r);
        x[l + 1] = 1;
        subset1(x, l + 1, r);
        x[l + 1] = 2;
        subset1(x, l + 1, r);
        x[l + 1] = 3;
        subset1(x, l + 1, r);
    }
}

int main() {
    int n = 4;            // Number of elements
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n);

    return 0;
}
