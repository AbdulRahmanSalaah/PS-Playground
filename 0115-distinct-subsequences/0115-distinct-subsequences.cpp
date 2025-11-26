class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m)
            return 0;
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        return dfs(0, 0, s, t, dp);
    }
    long long dfs(int i, int j, string& s, string& t,
                  vector<vector<long long>>& dp) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

            
        long long ways = 0;

        // take
        if (s[i] == t[j]) {
            ways += dfs(i + 1, j + 1, s, t, dp);
        }

        // skip s[i]
        ways += dfs(i + 1, j, s, t, dp);

        dp[i][j] = ways;
        return dp[i][j];
    }
};