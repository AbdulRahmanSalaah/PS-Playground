class Solution {
    int dx[4] = {0, 1, 0, -1}; // row directions
    int dy[4] = {1, 0, -1, 0}; // col directions
    
    bool valid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {

        if (!valid(i, j, n, m) || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';

        for (int d = 0; d < 4; d++) {
            int nr = i + dx[d];
            int nc = j + dy[d];
            dfs(grid, nr, nc, n, m);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int nIslands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    nIslands++;
                }
            }
        }
        return nIslands;
    }
};