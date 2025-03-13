#include <iostream>
#include <vector>

using namespace std;

int totalCoinDown(vector<vector<int> > &DP, vector<int> &coin, int n,int k){
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

int totalCoinTop(vector<vector<int>> &DP, vector<int> &coin, int n, int k) {
    if (k == 0) return 1;
    
    if (n == 0) return 0;

    if (DP[n][k] != -1) return DP[n][k];

    int exclude = totalCoin(DP, coin, n - 1, k);
    
    int include = 0;
    
	if (coin[n - 1] <= k) {
	    include = totalCoin(DP, coin, n, k - coin[n - 1]);
	}


    DP[n][k] = exclude + include;
    
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
	
	cout<<totalCoinTop(DP,coin,n,w);
}
