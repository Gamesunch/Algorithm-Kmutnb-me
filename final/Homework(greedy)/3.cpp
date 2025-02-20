#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<float, int>> train;

    float ta, tb;
    for (int i = 0; i < n; i++) {
        cin >> ta >> tb;
        train.push_back({ta, 1});  // Arrival event
        train.push_back({tb, -1}); // Departure event
    }

    sort(train.begin(), train.end());

    int maxPlatforms = 0, currentPlatforms = 0;
    
    
    for (int i = 0; i < train.size(); i++) {
        currentPlatforms += train[i].second;
        if (currentPlatforms > maxPlatforms) {
            maxPlatforms = currentPlatforms;
        }
    }

    cout << maxPlatforms << endl;

    return 0;
}

/*
6
2.00 2.30
2.10 3.40
3.00 3.20
3.20 4.30
3.50 4.00
5.00 5.20
*/

