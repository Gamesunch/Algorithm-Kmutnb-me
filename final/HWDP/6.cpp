#include <iostream>
#include <vector>
using namespace std;

vector<int> DP(1000,-1);

int stair(int n,int m){
	if(n == 0){
		return 1;
	}
	
	if(n < 0){
		return 0;
	}
	
	int step = 0;
	for(int i = 1;i<=m;i++){
		step += stair(n-i,m);
	}
	
	DP[n] = step;
	return DP[n];
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	cout<<stair(n,m)<<endl;
}
