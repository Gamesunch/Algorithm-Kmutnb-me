#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int c = 0;
	int A[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	for(int i = 0;i<n-1;i++){
		for(int j = i+1;j<n;j++){
			if(A[i] + A[j] == k){
				cout<<A[i]<<" "<<A[j]<<endl;
				c++;
			}
		}
	}
	
	if(c == 0){
		cout<<"-1"<<endl;
	}
}
