#include <iostream>

using namespace std;

int A[10000];

int stone(int l,int r){
	if(r-l+1 == 3){
		if(A[l] == A[l+1] && A[l]!= A[r]){
			return r;
		}
		else if(A[l] != A[l+1] && A[l] == A[r]){
			return l+1;
		}else if(A[l+1] == A[r] && A[r] != A[l]){
			return l;
		}
		
	}else{
		int st = l+(r-l)/3;
		int first = stone(l,st);
		int second = stone(st+1,st+1+st);
		int third = stone(st+2+st, r);
		
		if(A[first] == A[second] && A[first]!= A[third]){
			return third;
		}
		else if(A[first] != A[second] && A[first] == A[third]){
			return second;
		}else if(A[second] == A[third] && A[third] != A[first]){
			return first;
		}
	}
	
}


int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin>>A[i];
	}
	
	cout << stone(0,n-1);
}
