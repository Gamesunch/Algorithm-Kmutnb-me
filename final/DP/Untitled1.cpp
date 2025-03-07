#include <iostream>
#include <vector>
using namespace std;

vector<int> memo1 (1000,-1);
vector<int> memo2 (1000,-1);

unsigned long long RecursiveFac(unsigned long long n){
	if(n == 1){
		return 1;
	}
	
	return n * RecursiveFac(n-1);
}

unsigned long long TopDownFac(unsigned long long n){
	if(n == 1){
		return 1;
	}
	
	if(memo1[n] != -1){
		return memo1[n];
	}
	
	memo1[n] = n * TopDownFac(n-1);
	
	return memo1[n];
}

unsigned long long ButtomUpFac(unsigned long long n){
	memo2[1] = 1;
	for(int i = 2;i <= n; i++){
		memo2[i] = i * memo2[i-1];
	}
	
	return memo2[n];
}


int main(){
	unsigned long long n,k;
	cin>>n;
	
	cout<<RecursiveFac(n)<<endl;
	cout<<TopDownFac(n)<<endl;
	cout<<ButtomUpFac(n)<<endl;
	
	
}
