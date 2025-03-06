#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 105;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int n;

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
	    int v = adj[u][i];
	    if (!visited[v]) {
	        dfs(v);
	    }
	}
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < n; i++) {
        int p, q;
        cin >> p;
        while (true) {
            cin >> q;
            if (q == 0) break;
            adj[p].push_back(q);
        }
    }

    int k, s;
    cin >> k;
    vector<int> startNodes;
    for (int i = 0; i < k; i++) {
        cin >> s;
        startNodes.push_back(s);
    }

    for (int i = 0; i < k; i++) {
        int start = startNodes[i];
        memset(visited, false, sizeof(visited));
        dfs(start);

        vector<int> unreachable;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                unreachable.push_back(j);
            }
        }

        if (unreachable.empty()) {
            cout << "0" << endl;
        } else {
            for (int j = 0; j < unreachable.size(); j++) {
                cout << unreachable[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
/*
3
1 2 0
2 2 0
3 1 2 0
3 1 2 3
*/
