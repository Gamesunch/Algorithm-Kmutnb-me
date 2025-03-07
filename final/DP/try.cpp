#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > memo (100,vector<int> (100,-1));

//recursive normal
int walk(int n,int k){
	if(n == 1 || k == 1){
		return 1;
	}
	
	return walk(n,k-1) + walk(n-1,k);
}

//Top-Down
int walkTop(int n,int k){
	if(n == 1 || k == 1){
		return 1;
	}
	
	if(memo[n][k] != -1){
		return memo[n][k];
	}
	
	memo[n][k] = walkTop(n,k-1) + walkTop(n-1,k);
	return memo[n][k];
	
}
int main(){
	int n,k;
	cin>>n>>k;
	
	cout<<walk(n,k)<<endl;
	cout<<walkTop(n,k)<<endl;
	return 0;
}
