#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long long> dp(1000,-1);

unsigned long long febo(int n){
	if(n <= 2){
		return 1;
	}
	
	if(dp[n] != -1){
		return dp[n];
	}
	
	dp[n] = 3*febo(n-1) + febo(n-2);
	return dp[n];
}

int main(){
	unsigned long long n;
	cin>>n;
	
	cout<<febo(n);
}
