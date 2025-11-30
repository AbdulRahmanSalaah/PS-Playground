class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        return dfs(0, n + 1, a, dp);
    }

    int dfs(int l, int r, vector<int>& a, vector<vector<int>>& dp) {
        if (l + 1 == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        for (int k = l + 1; k < r; k++) {
            int coins =
                a[l] * a[k] * a[r] + dfs(l, k, a, dp) + dfs(k, r, a, dp);

            ans = max(ans, coins);
        }
        dp[l][r] = ans;
        return dp[l][r];
    }
};