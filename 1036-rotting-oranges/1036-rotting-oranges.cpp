class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;

    bool valid(int i, int j) { 
        return i >= 0 && j >= 0 && i < n && j < m; 
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;

        // Count fresh oranges and push rotten ones to queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (valid(nx, ny) && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // rot the orange
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            time++; // one minute passed
        }

        return (fresh == 0) ? time : -1;
    }
};
