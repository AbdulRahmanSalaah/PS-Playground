class Solution {
    int dx[4] = {0, 1, 0, -1}; // row directions
    int dy[4] = {1, 0, -1, 0}; // col directions

    bool valid(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }
    int n, m;

    void dfs(vector<vector<char>>& grid, int i, int j) {

        if (!valid(i, j) || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        for (int d = 0; d < 4; d++) {
            int nr = i + dx[d];
            int nc = j + dy[d];
            dfs(grid, nr, nc);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int nIslands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    nIslands++;
                }
            }
        }
        return nIslands;
    }
};