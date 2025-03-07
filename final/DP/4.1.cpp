#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > memo1 (1000,vector<int> (1000,-1));
vector<vector<int> > memo11 (1000,vector<int> (1000,0));
vector<int> memo2 (1000,-1);

//f(n,k) = F(n-1,k) + F(n-1,k-2) base-case = F(n,0) = 1, F(n,1) = 1, F(n,n) = 1;
//top down;
int FTop(int n, int k){
	if(k <= 1 || n == k){
		return 1;
	}
	
	if(memo1[n][k] != -1){
		return memo1[n][k];
	}
	
	memo1[n][k] = FTop(n-1,k) + FTop(n-1,k-2);
	return memo1[n][k];
}
int FDown(int n, int k){
	for(int i = 0;i<n;i++){
		memo11[n][n] = 1;
		memo11[n][0] = 1;
		memo11[n][1] = 1;
	}
	
	for(int i = 3;i<=n;i++){
		for(int j = 2; j<n;j++){
			if(i > j){
				memo11[i][j] = memo11[i-1][j] + memo11[i-1][j-2];
			}
		}
	}
	
	return memo11[n][k];
}

//G(n) = G(n-1) + G(n-2) - G(n-3) base-case = G(0) = 0, G(1) = 1, G(2) = 1;
//top down
int GTop(int n){
	if(n == 0){
		return 0;
	}
	if(n == 2 || n == 1){
		return 1;
	}
	
	if(memo2[n] != -1){
		return memo2[n];
	}
	
	memo2[n] = GTop(n-1) + GTop(n-2) - GTop(n-3);
	
	return memo2[n];
}
//buttom down;
int GDown(int n){
	memo2[0] = 0;
	memo2[1] = 1;
	memo2[2] = 1;
	
	for(int i = 3;i<=n;i++){
		memo2[i] = memo2[i-1] + memo2[i-2] - memo2[i-3];
	}
	
	return memo2[n];
}

int main(){
	int n,k,j;
	cin>>n>>k;
//	cout<<FTop(n,k)<<endl; // 8
	cout<<FDown(n,k)<<endl;
	cin>>j;
	cout<<GTop(j)<<endl; //4
	cout<<GDown(j)<<endl; //4
	return 0;
}
