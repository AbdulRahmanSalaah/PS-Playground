class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums)
            total += x;

        // dp[i][sum + total] = number of ways
        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * total + 1, INT_MIN));
        return dfs(0, 0, nums, target, dp, total);
    }

    int dfs(int i, int currSum, vector<int>& nums, int target,
            vector<vector<int>>& dp, int offset) {
        if (i == nums.size())
            return currSum == target ? 1 : 0;

        int shifted = currSum + offset;
        if (dp[i][shifted] != INT_MIN)
            return dp[i][shifted];

        int add = dfs(i + 1, currSum + nums[i], nums, target, dp, offset);
        int sub = dfs(i + 1, currSum - nums[i], nums, target, dp, offset);

        dp[i][shifted] = add + sub;
        return dp[i][shifted];
    }
};