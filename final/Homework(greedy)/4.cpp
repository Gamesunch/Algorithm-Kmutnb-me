#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int ans;
	int SumLeft,SumRight;
	
	cin>>n;
	int A[n*2];
	
	for(int i = 0;i<n*2;i++){
		cin>>A[i];
	}
	
	sort(A,A+n,greater<int>());
	SumLeft = A[0];
	SumRight = A[1];
	
	for(int i = 2;i<n*2;i++){
		if(SumLeft >= SumRight){
			SumRight += A[i];
		}
		else{
			SumLeft += A[i];
		}
	}
	
	cout<<SumLeft<<endl;
	cout<<SumRight<<endl;
	
	cout<<abs(SumLeft - SumRight)<<endl;
    
    return 0;
}

/*
6
12 20 19 45 2 30

7
4 12 13 29 31 32 50
*/
