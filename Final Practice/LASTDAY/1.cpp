#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int C(int n,int m){
	return 2*n + m;
}

int P(int n,int m,vector<vector<int> > &DP){
	if(n == 0){
		return 3*m;
	}
	
	if(m == 0){
		return 2*n;
	}
	
	if(DP[n][m] != -1){
		return DP[n][m];
	}
	
	DP[n][m] = min(P(n-1,m,DP) + 2, min(P(n,m-1,DP) + 3, P(n-1,m-1,DP) + C(n,m)));
	
	return DP[n][m];
	
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	vector<vector<int> > DP(n+1, vector<int> (m+1,-1));
	
	cout<<P(n,m,DP);
	
}
