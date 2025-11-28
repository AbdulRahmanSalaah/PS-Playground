class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(0, 0, word1, word2, dp);
    }
    int dfs(int i, int j, string& word1, string& word2,
            vector<vector<int>>& dp) {
        if (i == word1.size()) {
            return word2.size() - j; // insert all remaining chars of word2
        }
        if (j == word2.size()) {
            return word1.size() - i; // delete all remaining chars of word1
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            dp[i][j] = dfs(i + 1, j + 1, word1, word2, dp);
        } else {
            int insert = 1 + dfs(i, j + 1, word1, word2, dp);
            int remove = 1 + dfs(i + 1, j, word1, word2, dp);
            int replace = 1 + dfs(i + 1, j + 1, word1, word2, dp);
            dp[i][j] = min({insert, remove, replace});
        }
        return dp[i][j];
    }
};