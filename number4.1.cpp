#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> searchKNearest(vector<int>& A, int M, int k) {
    sort(A.begin(), A.end());

    //Find the index i for the target M or the closest element to M
    int i;
    for(int j = 0;j<A.size();j++){
    	if(A[j] >= M){
    		i = j;
			break;	
		}
	}
    
    cout<<i<<endl;

    int left = i - 1;
    int right = i;

    while ((right - left) <= k) {
    	cout<<left<<" "<<right<<endl;
        if(abs(A[left] - M > abs(A[right] - M))){
        	right++;
		}
		else{
			left--;
		}
    }

    vector<int> result;
    for (int j = left + 1; j < right; j++) {
        result.push_back(A[j]);
    }

    return result;
}

int main() {
    vector<int> A = {10, 12, 15, 17, 18, 20, 25};
    int M = 8;
    int k = 2;

    vector<int> result = searchKNearest(A, M, k);
    
    cout<<"------------------"<<endl;

    for(int i = 0;i<result.size();i++){
    	cout<<result[i]<<" ";
	}
	cout<<endl;

    return 0;
}

