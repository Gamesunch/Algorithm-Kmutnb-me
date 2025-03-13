#include <iostream>
#include <vector>

using namespace std;

int totalCoin(vector<vector<int> > &DP, vector<int> &coin, int n,int k){
	for(int i = 0;i<=n;i++){
		DP[i][0] = 1;
	}
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=k;j++){
			
			DP[i][j] = DP[i-1][j];
			
			if(coin[i - 1] <= j){
				
				DP[i][j] += DP[i][j - coin[i-1]];
			}
		}
	}
	
	return DP[n][k];
}

int main(){
	int n,w;
	
	cin>>n>>w;
	
	vector<int> coin (n);
	
	for(int i = 0;i<n;i++){
		cin>>coin[i];
	}
	
	vector<vector<int> > DP (n+1, vector<int> (w+1,0));
	
	cout<<totalCoin(DP,coin,n,w);
}
