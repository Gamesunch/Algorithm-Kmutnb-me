#include <iostream>
#include <vector>

using namespace std;

int cross(int n,int m,vector<int> &DP,vector<bool> &danger){
	if(n == 0){
		return 1;
	}
	
	if(n < 0 || danger[n]){
		return 0;
	}
	
	if(DP[n] != -1){
		return DP[n];
	}
	
	int crossing = 0;
	
	for(int i = 1 ; i<= m;i++){
		crossing += cross(n-i,m,DP,danger);
	}
	
	DP[n] = crossing;
	
	return DP[n];
}

int main(){
	int n,m,k;
	cin>>n>>m;
	
	vector<int> DP(n+1,-1);
	
	cin>>k;
	
	vector<bool> danger(k+1,false);
	
	for(int i = 0;i<k;i++){
		int dan;
		cin>>dan;
		danger[dan] = true;
	}
	
	cout<<cross(n,m,DP,danger);
}
