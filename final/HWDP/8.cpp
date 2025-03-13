#include <iostream>
#include <vector>
using namespace std;

vector<long double> DP(2000000,-1);

long double mean(unsigned long long x[], int n){
	if(n == 1){
		return x[n-1];
	}
	
	if(DP[n] != -1){
		return DP[n];
	}
	
	DP[n] = (mean(x,n-1) * (n-1) + x[n-1])/n;
	
	return DP[n];
}

int main(){
	unsigned long long n;
	
	cin>>n;
	
	unsigned long long x[n];
	
	for(int i = 0;i<n;i++){
		cin>>x[i];
	}
	
	cout<<mean(x,n);
}
