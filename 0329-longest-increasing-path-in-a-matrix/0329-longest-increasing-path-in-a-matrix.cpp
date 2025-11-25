class Solution {
    int dx[4] = {0, 1, 0, -1}; // row directions
    int dy[4] = {1, 0, -1, 0}; // col directions
    int n, m;
    bool valid(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }
    vector<vector<int>> dp;
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int best = 1;
        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if (valid(nx, ny) && matrix[nx][ny] > matrix[i][j]) {
                best = max(best, 1 + dfs(nx, ny, matrix));
            }
        }
        dp[i][j] = best;
        return dp[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};