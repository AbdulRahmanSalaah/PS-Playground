class Solution {
    vector<int> memo;

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memo.assign(n + 1, -1);
        return helper(cost, n);
    }

    int helper(vector<int>& cost, int i) {
        if (i == 0)
            return cost[0];
        if (i == 1)
            return cost[1];

        if (memo[i] != -1)
            return memo[i];

        if (i == cost.size()) {
            return memo[i] = min(helper(cost, i - 1), helper(cost, i - 2));
        }

        return memo[i] = cost[i] + min(helper(cost, i - 1), helper(cost, i - 2));
    }
};
