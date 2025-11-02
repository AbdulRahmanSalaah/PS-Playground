class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return rec(0, n, true, dp, prices);
    }

    int rec(int i, int n, bool canBuy, vector<vector<int>>& dp,
            vector<int>& prices) {
        if (i >= n) {
            return 0;
        }
        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];

        int profit = 0;

        if (canBuy) {
            int buy = -prices[i] + rec(i + 1, n, false, dp, prices);
            int skip = rec(i + 1, n, true, dp, prices);
            profit = max(buy, skip);
        } else {
            int sell = prices[i] + rec(i + 2, n, true, dp, prices);
            int hold = rec(i + 1, n, false, dp, prices);
            profit = max(sell, hold);
        }
        dp[i][canBuy] = profit;
        return dp[i][canBuy];
    }
};