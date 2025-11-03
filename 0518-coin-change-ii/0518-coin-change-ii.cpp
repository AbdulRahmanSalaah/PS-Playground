class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return rec(0, amount, coins, dp);
    }
    int rec(int i, int rem, vector<int>& coins, vector<vector<int>>& dp) {
        if (rem == 0)
            return 1;
        if (i == coins.size() || rem < 0) {
            return 0;
        }

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int take = rec(i, rem - coins[i], coins, dp);
        int skip = rec(i + 1, rem, coins, dp);
        dp[i][rem] = take + skip;
        return dp[i][rem];
    }
};