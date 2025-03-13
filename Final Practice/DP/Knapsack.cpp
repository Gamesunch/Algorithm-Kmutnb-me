#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int> &val, vector<int> &wt, vector<vector<int> > &DP, int w, int index){
	if(index < 0){
		return 0;
	}
	
	if(DP[index][w] != -1){
		return DP[index][w];
	}
	
	if(wt[index] > w){
		DP[index][w] = knapsack(val,wt,DP,w,index-1);
	}
	else{
		DP[index][w] = max(val[index] + knapsack(val,wt,DP, w - wt[index],index - 1), knapsack(val,wt,DP,w,index-1));
	}
	
	return DP[index][w];
}

int main(){
	int n,w;
	
	cin>>n>>w;
	
	vector<int> val (n);
	vector<int> wt (n);
	
	vector<vector<int> > DP (n+1,vector<int> (w+1, -1));
	
	for(int i = 0;i<n;i++){
		cin>>val[i];
	}
	
	for(int i = 0;i<n;i++){
		cin>>wt[i];
	}
	
	cout<<knapsack(val,wt,DP,w,n-1)<<endl;
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=w;j++){
			cout<<DP[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
}
