class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;

    bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q,
             vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (valid(nx, ny) && !visited[nx][ny] &&
                    heights[nx][ny] >= heights[x][y]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> q_pac, q_atl;
        // Pacific borders (left column + top row)
        for (int i = 0; i < n; i++) {
            pacific[i][0] = true;
            q_pac.push({i, 0});
        }
        for (int j = 0; j < m; j++) {
            pacific[0][j] = true;
            q_pac.push({0, j});
        }
        // Atlantic borders (right column + bottom row)
        for (int i = 0; i < n; i++) {
            atlantic[i][m - 1] = true;
            q_atl.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            atlantic[n - 1][j] = true;
            q_atl.push({n - 1, j});
        }

        bfs(heights, q_pac, pacific);
        bfs(heights, q_atl, atlantic);

        // Collect cells reachable by both oceans
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};