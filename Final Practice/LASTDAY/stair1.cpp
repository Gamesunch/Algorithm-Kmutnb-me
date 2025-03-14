#include <iostream>
#include <vector>

using namespace std;

long int cross(long int n,long int m,vector<long int> &DP){
	if(n == 0){
		return 1;
	}
	if(n < 0){
		return 0;
	}
	
	if(DP[n] != -1){
		return DP[n];
	}
	
	long int stair = 0;
	for(int i = 1;i<=m;i++){
		stair += cross(n-i,m,DP);
	}
	
	DP[n] = stair;
	
	return DP[n];
}

int main(){
	long int n,m;
	
	cin>>n>>m;
	
	vector<long int> DP(n+1,-1);
	
	cout<<cross(n,m,DP);
}
