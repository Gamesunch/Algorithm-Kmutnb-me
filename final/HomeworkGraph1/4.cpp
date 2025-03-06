#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(const vector<vector<int>>& graph, int start, int m, int V) {
    vector<int> visited(V + 1, -1);
    visited[start] = 0;
    
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        int current_distance = visited[node];
        
        if (current_distance >= m) {
            continue;
        }

        for (int neighbor : graph[node]) {
            if (visited[neighbor] == -1) {
                visited[neighbor] = current_distance + 1;
                q.push(neighbor);
            }
        }
    }
    
    int count = 0;
    for (int i = 1; i <= V; ++i) {
        if (visited[i] == -1) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V + 1);

    int p, q;
    while (true) {
        cin >> p >> q;
        if (p == 0 && q == 0) {
            break;
        }
        graph[p].push_back(q);
    }

    int k, m;
    cin >> k >> m;

    int result = bfs(graph, k, m, V);
    
    cout << result << endl;

    return 0;
}
/*
7
1 2
1 4
1 5
2 3
2 5
3 1
3 6
3 7
4 5
5 4
6 5
6 7
0 0
1 2
*/
