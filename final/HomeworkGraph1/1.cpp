#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void BFS(vector<vector<int>> &adj, int V, int src, int des) {
    queue<int> q;
    vector<int> dist(V, -1);
    vector<int> parent(V, -1);

    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);

                if (v == des) break;
            }
        }
    }

    cout << dist[des] << endl;
}

int main() {
    int n, start, des;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    int p, q;
    for (int i = 0; i < n; i++) {
        cin >> p;
        while (true) {
            cin >> q;
            if (q == 0) break;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
    }

    cin >> start >> des;

    BFS(adj, n + 1, start, des);

    return 0;
}


/*
6
1 2 3 0
2 1 4 0
3 1 4 0
4 2 3 5 0
5 4 6 0
6 5 0

*/
