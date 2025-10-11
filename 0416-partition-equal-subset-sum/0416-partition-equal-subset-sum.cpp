class Solution {
    vector<vector<int>> memo;

public:
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalsum += nums[i];
        }
        if (totalsum % 2) {
            return false;
        }

        int target = totalsum / 2;

        memo.assign(nums.size(), vector<int>(target + 1, -1));

        return dfs(nums, 0, target);
    }

    bool dfs(vector<int>& nums, int i, int rem) {
        if (rem == 0)
            return true;

        if (i >= nums.size() || rem < 0)
            return false;

        if (memo[i][rem] != -1)
            return memo[i][rem];

        bool take = dfs(nums, i + 1, rem - nums[i]);
        bool skip = dfs(nums, i + 1, rem);

        memo[i][rem] = take || skip;
        return memo[i][rem];
    }
};