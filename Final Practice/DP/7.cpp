#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > DP(1000,vector<int> (1000,-1));

unsigned long long walkTop(unsigned long long n,unsigned long long m){
	if(n == 1 || m == 1){
		return 1;
	}
	
	if(DP[n][m] != -1){
		return DP[n][m];
	}
	
	DP[n][m] = walkTop(n-1,m) + walkTop(n,m-1);
	
	return DP[n][m];
	
}


int main(){
	unsigned long long n,m;
	
	cin>>n>>m;
	
	cout<<walkTop(n,m);
}
