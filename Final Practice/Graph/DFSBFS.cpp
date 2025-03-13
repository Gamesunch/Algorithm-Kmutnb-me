#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int, vector<vector<int>> &);
void BFS(int, vector<vector<int>> &);

vector<int> visited;
int n, edge, start;

int main() {
    cin >> n >> edge >> start;
    
    vector<vector<int>> G(n);
    visited.assign(n, 0);

    int u, v;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    fill(visited.begin(), visited.end(), 0);
    cout << "DFS: ";
    DFS(start, G);
    cout << endl;

    fill(visited.begin(), visited.end(), 0);
    cout << "BFS: ";
    BFS(start, G);
    cout << endl;

    return 0;
}

void DFS(int node, vector<vector<int>> &G) {
    cout << node << " ";
    visited[node] = 1;

    for (int neighbor : G[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, G);
        }
    }
}

void BFS(int start, vector<vector<int>> &G) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : G[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

