#include <bits/stdc++.h>
using namespace std;

int Zebra(int n,int m,vector<int> &DP){
	if(n == 0){
		return 1;
	}
	
	if(n < 0){
		return 0;
	}
	
	if(DP[n] != -1){
		return DP[n];
	}
	
	int step = 0;
	for(int i = 1;i<=m;i++){
		step += Zebra(n-i,m,DP);
	}
	
	DP[n] = step;
	return DP[n];
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	vector<int> DP(n+1,-1);
	
	cout<<Zebra(n,m,DP);
	
	
}
