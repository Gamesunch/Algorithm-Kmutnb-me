#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<unsigned long long> memoG (1000,ULLONG_MAX);
vector<unsigned long long> memoT (1000,ULLONG_MAX);

unsigned long long G(int n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return 2;
	}
	
	if(memoG[n] != ULLONG_MAX){
		return memoG[n];
	}
	
	memoG[n] = G(n-1) + G(n-2);
	
	return memoG[n];
}

unsigned long long T(int n){
	if(n == 0){
		return 1;
	}
	
	if(memoT[n] != ULLONG_MAX){
		return memoT[n];
	}
	
	memoT[n] = T(n-1) + G(n/2) + n;
	
	return memoT[n];
}

int main(){
	unsigned long long n;
	cin>>n;
	
	cout<<G(n)<<endl;
	cout<<T(n)<<endl;
}
