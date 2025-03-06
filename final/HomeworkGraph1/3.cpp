#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &adj, int start, int V, vector<bool> &visited, vector<int> &parent) {
    visited[start] = true;

    for (int i = 0; i < V; i++) {
        if (adj[start][i] == 1) {
            if (!visited[i]) {
                parent[i] = start;
				dfs(adj, i, V, visited, parent);
            }
            else if (visited[i] && parent[start] != i) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    for (int i = 1; i < V; i++) {
        if (!visited[i]) {
            if (dfs(adj, i, V, visited, parent)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    int p, q;
    for (int i = 0; i < n; i++) {
        cin >> p;
        while (true) {
            cin >> q;
            if (q == 0) break;
            adj[p][q] = 1;
            adj[q][p] = 1;
        }
    }

    if (isCycle(n + 1, adj)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

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
