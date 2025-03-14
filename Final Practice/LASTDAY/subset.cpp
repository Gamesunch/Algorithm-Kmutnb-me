#include <iostream>
using namespace std;

void subset(int x[],int l,int r){
	if(l == r){
		for(int i = 0;i<r;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
	else{
		x[l] = 1;
		subset(x,l+1,r);
		x[l] = 0;
		subset(x,l+1,r);
	}
	
	
}

int main(){
	int n;
	cin>>n;
	
	int x[n] = {0};
	
	subset(x,0,n);
	
	
}
