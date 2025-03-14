#include <iostream>
using namespace std;

void purmute(int x[],int start,int end){
	if(start == end){
		for(int i = 0;i<=end;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	
	for(int i = start;i<=end;i++){
		swap(x[start],x[i]);
		purmute(x,start + 1, end);
		swap(x[start],x[i]);
	}
}

int main(){
	int n;
	cin>>n;
	
	int x[n];
	
	for(int i = 0;i<n;i++){
		x[i] = i + 1;
	}
	
	purmute(x,0,n-1);
}
