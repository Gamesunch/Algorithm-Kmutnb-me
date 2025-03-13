#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoin(vector<vector<int>> &DP, vector<int> &coin, int n, int k) {
	
	//handle impossible case
	for (int j = 0; j <= k; j++){
		DP[0][j] = 10000 - 1;
	}

    for (int i = 0; i <= n; i++){
    	DP[i][0] = 0;
	}
        
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            DP[i][j] = DP[i-1][j];
            if (coin[i-1] <= j) {
            	
                DP[i][j] = min(DP[i][j], 1 + DP[i][j - coin[i-1]]);
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
	
	cout<<minCoin(DP,coin,n,w);
}
/*
4 15
2 3 5 10
*/
