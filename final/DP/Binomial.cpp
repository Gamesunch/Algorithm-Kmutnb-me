#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > memo1 (1000,vector<int> (1000,-1));
vector<vector<int> > memo2 (1000,vector<int> (1000,-1));

unsigned long long RecursiveFac(unsigned long long n){
	if(n == 0){
		return 1;
	}
	
	return n * RecursiveFac(n-1);
}

unsigned long long Binominal(unsigned long long n, unsigned long long k){
	return (RecursiveFac(n))/(RecursiveFac(n-k) * RecursiveFac(k));
}

//top down
unsigned long long BiominalTop(unsigned long long n,unsigned long long k){
	if(n == k || k == 0){
		return 1;
	}
	
	if(memo1[n][k] != -1){
		return memo1[n][k];
	}
	
	memo1[n][k] = BiominalTop(n-1,k-1) + BiominalTop(n-1,k);
	return memo1[n][k];
}

//Buttom up
unsigned long long BiominalDown(unsigned long long n,unsigned long long k){
	for(int i = 0;i<n;i++){
		memo2[i][0] = 1;
		memo2[i][i] = 1;
	}
	
	for(int i = 2; i<= n;i++){
		for(int j = 1; j < n;j++){
			if(i > j){
				memo2[i][j] = memo2[i-1][j-1] + memo2[i-1][j];
			}
		}
	}
	
	return memo2[n][k];
}

int main(){
	unsigned long long n,k;
	
	cin>>n>>k;
	
	cout<<Binominal(n,k)<<endl;
	cout<<BiominalTop(n,k)<<endl;
	cout<<BiominalDown(n,k)<<endl;
}
