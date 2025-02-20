#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> Line;

    int xi, xj;
    for (int i = 0; i < n; i++) {
        cin >> xi >> xj;
        Line.push_back({xi, xj});
    }

    int xa,xb;
    cin>>xa>>xb;

    sort(Line.begin(), Line.end());

    vector<pair<int, int>> result;
    int covered = xa, i = 0, maxReach = xa;

    while (covered < xb) {
        int bestSegment = -1;

        //find most cover range
        while (i < n && Line[i].first <= covered) {
            if (Line[i].second > maxReach) {
                maxReach = Line[i].second;
                bestSegment = i;
            }
            i++;
        }

        //can't find range
        if (bestSegment == -1) {
            return 0;
        }
        
        result.push_back(Line[bestSegment]);
        covered = maxReach;
    }

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
/*
input
10
1 2
3 5
1 5
2 4
4 5
3 6
2 7
7 9
4 8
1 3
1 9

output
3
1 5
4 8
7 9
*/

