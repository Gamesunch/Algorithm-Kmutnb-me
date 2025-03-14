#include <bits/stdc++.h>
using namespace std;

int walk(int n,int m,vector<vector<int> > &DP){
	if(n == 1 || m == 1){
		return 1;
	}
	
	if(n <= 0 || m <= 0){
		return 0;
	}
	
	if(DP[n][m] != -1){
		return DP[n][m];
	}
	
	DP[n][m] = walk(n-1,m,DP) + walk(n,m-1,DP);
	
	return DP[n][m];
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	vector<vector<int> > DP(n+1,vector<int> (m+1,-1));
	
	cout<<walk(n,m,DP);
}
