class Solution {
    vector<vector<int>> dp;

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size())
            return false;
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

        return dfs(0, 0, 0, s1, s2, s3);
    }
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (k == s3.size()) {
            return (i == s1.length()) && (j == s2.length());
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool res = false;
        // Try taking from s1
        if (i < s1.length() && s1[i] == s3[k]) {
            if (dfs(i + 1, j, k + 1, s1, s2, s3)) {
                dp[i][j] = 1;
                return true;
            }
        }

        // Try taking from s2
        if (j < s2.length() && s2[j] == s3[k]) {
            if (dfs(i, j + 1, k + 1, s1, s2, s3)) {
                dp[i][j] = 1;
                return true;
            }
        }

        dp[i][j] = 0;
        return false;
    }
};