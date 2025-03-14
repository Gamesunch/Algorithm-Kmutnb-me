#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumPossible(vector<int> &weights, vector<vector<bool>> &dp, int target, int index) {
    
    if (target == 0) return true;
    
    if (index < 0) return false;
    
    if (dp[index][target] != -1) return dp[index][target];

    if (weights[index] > target) {
        dp[index][target] = isSubsetSumPossible(weights, dp, target, index - 1);
    } else {
        dp[index][target] = isSubsetSumPossible(weights, dp, target - weights[index], index - 1) || isSubsetSumPossible(weights, dp, target, index - 1);
    }
    
    return dp[index][target];
}

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> weights(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    if (isSubsetSumPossible(weights, dp, target, n - 1)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

