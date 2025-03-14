#include <iostream>
#include <vector>

using namespace std;

int stair(int n,int m,vector<int> &DP,vector<int> &jumps){
	if(n == 0){
		return 1;
	}
	
	if(n < 0){
		return 0;
	}
	
	if(DP[n] != -1){
		return DP[n];
	}
	
	int stairsum = 0;
	for(int i = 0;i<jumps.size();i++){
		stairsum += stair(n-jumps[i],m,DP,jumps);
	}
	
	DP[n] = stairsum;
	return DP[n];
}

int main(){
	int n,m;
	cin>>n>>m;
	
	vector<int> jumps(m);
	
	vector<int> DP(n+1,-1);
	
	for(int i = 0;i<m;i++){
		cin>>jumps[i];
	}
	
	cout<<stair(n,m,DP,jumps);
}
