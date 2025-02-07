#include <iostream>
#include <algorithm>
using namespace std;

int ct = 0;
int n = 4;
int x[4];

void n_queens(int k){
	if(k == n){
		ct++;
		int flag = 0;
    
	    for(int j = 1;j < k;j++){
	    	for(int p = 0; p < j;p++){
	    		if(abs(p-j) == abs(x[p]-x[j]) || x[j] == x[p]){
	    			flag = 1;
				}
			}
		}
		
		if(flag == 0){
			for(int i = 0;i<k;i++){
				cout<<x[i]<<" ";
			}
			cout<<endl;
		}
	}
	else{
		for(int row = 0; row < n; row++){
			
			int flag = 1;
			
			for(int j = 1;j < k;j++){
		    	for(int p = 0; p < j;p++){
		    		if(abs(p-j) == abs(x[p]-x[j]) || x[j] == x[p]){
		    			flag = 0;
					}
				}
			}
			
			x[k] = row;
			
			if(flag ==  1){	
				n_queens(k+1); 
			}
			
		}
	}
}

int main(){
	n_queens(0);
	cout<<ct<<endl;
	return 0;
}
