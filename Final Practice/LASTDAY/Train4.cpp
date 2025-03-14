#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	cin>>n;
	
	vector<pair<int,float> > train;
	
	float ta,tb;
	for(int i = 0;i<n;i++){
		cin >> ta >> tb;
		train.push_back({ta,1});
		train.push_back({tb,-1});
	}
	
	sort(train.begin(),train.end());
	
	int max = 0;
	int current = 0;
	
	for(int i = 0;i<train.size();i++){
		current += train[i].second;
		if(current > max){
			max = current;
		}
	}
	
	cout<<max;
}
/*
6
2.00 2.30
2.10 3.40
3.00 3.20
3.20 4.30
3.50 4.00
5.00 5.20
*/
