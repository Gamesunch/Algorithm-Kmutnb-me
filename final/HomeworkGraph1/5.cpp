#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = {0, 0, -1, 1};  // Left, Right
const int dy[] = {-1, 1, 0, 0};  // Up, Down

int floodFill(vector<vector<char>>& grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    char targetColor = grid[y][x];
    char newColor = 'G';
    
    if (targetColor == newColor) return 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    grid[y][x] = newColor;
    int filledCount = 1;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int cy = current.first, cx = current.second;

        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i], nx = cx + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && grid[ny][nx] == targetColor) {
                grid[ny][nx] = newColor;
                q.push({ny, nx});
                filledCount++;
            }
        }
    }

    return filledCount;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int x, y;
    cin >> y >> x;
    x--;
    y--;

    cout << floodFill(grid, x, y) << endl;

    return 0;
}

