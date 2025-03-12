#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maximum_s(int n,vector<int> &x, int k){
	vector<int> memo (k+1,-1);
	memo[0] = 0;
	
	for(int i = 0;i<n;i++){
		for(int j = k; j >= x[i];j--){
			if(memo[j - x[i]] != -1){
				memo[j] = max(memo[j],memo[j - x[i]] + 1);
			}
		}
	}
	
	return memo[k];
}

int main(){
	int n,k;
	
	cin>>n;
	
	vector<int> x(n);
	for(int i = 0;i<n;i++){
		cin>>x[i];
	}
	
	cin>>k;
	
	cout<<maximum_s(n,x,k);
	
	
}

