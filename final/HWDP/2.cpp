#include <iostream>
#include <vector>
using namespace std;

unsigned long long CTop(int n,int k){
	vector<vector<unsigned long long> > memo(1000, vector<unsigned long long> (1000,-1));
	
	if(k == 0 || n == k){
		return 1;
	}
	
	if(memo[n][k] != -1){
		return memo[n][k];
	}
	
	memo[n][k] = CTop(n-1,k-1) + CTop(n-1,k);
	
	return memo[n][k];
}

unsigned long long CButtom(int n,int k){
	vector<vector<unsigned long long> > memo(1000, vector<unsigned long long> (1000,-1));
	
	for(int i = 0;i<n;i++){
		memo[i][0] = 1;
		memo[i][i] = 1;
	}
	
	for(int i = 0;i<=n;i++){
		for(int j = 1;j<n;j++){
			if(i > j){
				memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
			}
		}
	}
	
	return memo[n][k];
}


int main(){
	int n,k;
	cin>>n>>k;
	
	cout<<CTop(n,k)<<endl;
	cout<<CButtom(n,k)<<endl;
}

/*
6 3
*/
