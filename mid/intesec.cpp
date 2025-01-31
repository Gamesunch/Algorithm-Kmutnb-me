#include <iostream>

using namespace std;

int countingIntesect[10000];

int countingUnion[10000];

int main(){
	int n;
	cin>>n;
	
	int A[n],B[n];
	
	for(int i = 0;i<n;i++){
		cin>>A[i];
		countingIntesect[A[i]] += 1;
	}
	
	for(int i = 0;i<n;i++){
		cin>>B[i];
		countingIntesect[B[i]] += 1;
	}
	
	//Intersect
	for(int i = 0;i<n;i++){
		if(countingIntesect[A[i]] == 2){
			cout<<A[i]<<" ";
		}
	}
	cout<<endl;
	
	//Union
	for(int i = 0;i<n;i++){
		if(countingUnion[A[i]] == 0){
			cout<<A[i]<<" ";
			countingUnion[A[i]]++;
		}
	}
	
	for(int i = 0;i<n;i++){
		if(countingUnion[B[i]] == 0){
			cout<<B[i]<<" ";
			countingUnion[B[i]]++;
		}
	}
	cout<<endl;
	
	return 0;
}
