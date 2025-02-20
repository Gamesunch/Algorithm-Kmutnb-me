#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	double A[n];
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	double ans = 0;
	double sum = 0;
	double temp = 0;
	
	sort(A,A + n);
	
	for(int i = 0;i<n;i++){
		sum += temp + A[i];
		temp = temp + A[i];
	}
	
	ans = sum/n;
	
	cout<<ans;
}
