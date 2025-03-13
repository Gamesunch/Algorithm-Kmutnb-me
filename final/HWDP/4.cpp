#include <iostream>
#include <vector>

using namespace std;

vector<vector<unsigned long long> > ATopDP (1000,vector<unsigned long long> (1000,-1));
vector<vector<unsigned long long> > ADownDP (1000,vector<unsigned long long> (1000,-1));
//F(n, k) = F(n-1, k) + F(n-1, k-2) when n >= k, F(n,0) = 1, F(n,1) = 1, F(n,n) = 1
unsigned long long ATop(int n,int k){
	
	if(k == 0 || k == 1 || n == k){
		return 1;
	}
	
	if(ATopDP[n][k] != -1){
		return ATopDP[n][k];
	}
	
	ATopDP[n][k] = ATop(n-1,k) + ATop(n-1,k-2);
	
	return ATopDP[n][k];
}

unsigned long long ADown(int n,int k){
	
	for(int i = 0;i<n;i++){
		ADownDP[i][i] = 1;
		ADownDP[i][0] = 1;
		ADownDP[i][1] = 1;
	}
	
	for(int i = 2;i<=n;i++){
		for(int j = 2;j<=k;j++){
			ADownDP[i][j] = ADownDP[i-1][j] + ADownDP[i-1][j-2];
		}
	}
	
	return ADownDP[n][k];
}
//G(n) = G(n-1) + G(n-2) – G(n-3), G(0) = 0, G(1) = 1, G(2) = 1
vector<unsigned long long> GTopDP(1000,-1);
vector<unsigned long long> GDownDP(1000,-1);

unsigned long long GTop(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	
	if(n == 0){
		return 0;
	}
	
	GTopDP[n] = GTop(n-1) + GTop(n-2) - GTop(n-3);
	
	return GTopDP[n];
	
}

unsigned long long GDown(int n){
	GDownDP[1] = 1;
	GDownDP[2] = 1;
	GDownDP[0] = 0;
	
	for(int i = 3;i<=n;i++){
		GDownDP[i] = GDownDP[i-1] + GDownDP[i-2] - GDownDP[i-3];
	}
	
	return GDownDP[n];
}
int main(){
	int n,k;
	
//	cin>>n>>k;
//	cout<<ATop(n,k)<<endl;
//	cout<<ADown(n,k)<<endl;

	cin>>n;
//	cout<<GTop(n)<<endl;
	cout<<GDown(n)<<endl;
}
