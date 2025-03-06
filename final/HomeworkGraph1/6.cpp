#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &adj, int N, int src, int &maxDist) {
    queue<int> q;
    vector<int> dist(N + 1, -1);

    q.push(src);
    dist[src] = 0;
    maxDist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                maxDist = max(maxDist, dist[v]);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int bestDistrict = 1, minMaxDist = N;

    for (int i = 1; i <= N; i++) {
        int maxDist;
        BFS(adj, N, i, maxDist);
        if (maxDist < minMaxDist) {
            minMaxDist = maxDist;
            bestDistrict = i;
        }
    }

    cout << bestDistrict << endl;
    return 0;
}

