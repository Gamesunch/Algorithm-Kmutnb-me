#include <bits/stdc++.h>

using namespace std;

int walkCost(int x1,int y1, int x2,int y2, vector<vector<int> > &A,vector<vector<int> > &DP){
	if(x2 == x1 && y2 == y1){
		return A[x1][y1];
	}
	
	if(x2 < x1 || y2 < y1){
		return 10000;
	}
	
	if(DP[x2][y2] != -1){
		return DP[x2][y2];
	}
	
	DP[x2][y2] = A[x2][y2] + min(walkCost(x1,y1,x2-1,y2,A,DP),walkCost(x1,y1,x2,y2-1,A,DP));
	
	return DP[x2][y2];
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	vector<vector<int> > A(n,vector<int> (m));
	vector<vector<int> > DP(n+1,vector<int> (m+1,-1));
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>A[i][j];
		}
	}
	
	int x1,y1,x2,y2;
	
	cin>>x1>>y1>>x2>>y2;
	
	cout<<walkCost(x1,y1,x2,y2,A,DP);
}
