#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > memoDown(1000, vector<int> (1000,-1));
vector<vector<int> > memoTop(1000, vector<int> (1000,-1));

int sugar(vector<vector<int> > &x, int n,int m){
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(i == 1 && j == 1){
				memoDown[i][j] = x[i][j];
			}
			else{
				int top = 0;
				int left = 0;
				if(i > 1){
					top = memoDown[i-1][j];
				}
				if(j > 1){
					left = memoDown[i][j-1];
				}
				
				memoDown[i][j] = x[i][j] + max(top,left);
			}
		}
	}
	
	return memoDown[n][m];
}

int sugarTop(vector<vector<int>> &x, int n, int m) {
	
    if (n < 1 || m < 1) {
        return 0; //if want min just change to large number
    }

    if (n == 1 && m == 1) {
        return x[n][m];
    }

    if (memoTop[n][m] != -1) {
        return memoTop[n][m];
    }

    memoTop[n][m] = x[n][m] + max(sugarTop(x,n-1,m), sugarTop(x,n,m-1)); //change to min for min value
    return memoTop[n][m];
}

int main(){
	int n,m;
	
	cin>>n>>m;
	
	vector<vector<int> > x(n+1,vector<int> (m+1,0));
	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>x[i][j];
		}
	}
	
	cout<<sugar(x,n,m)<<endl;
	cout<<sugarTop(x,n,m)<<endl;
	
	
}
