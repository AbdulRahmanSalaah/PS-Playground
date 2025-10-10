class Solution {
    vector<int> memo;

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, nums));
        }
        return ans;
    }

    int dfs(int i, vector<int>& nums) {
        if (memo[i] != -1)
            return memo[i];

        int best = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i])
                best = max(best, 1 + dfs(j, nums));
        }

        return memo[i] = best;
    }
};