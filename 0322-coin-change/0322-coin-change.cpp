class Solution {
    vector<int> memo;

public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount + 1, -2);
        return helper(coins, amount);
    }
    int helper(vector<int>& coins, int rem) {
        if (rem == 0)
            return 0;
        if (rem < 0)
            return -1;
        if (memo[rem] != -2)
            return memo[rem];

        int ans = INT_MAX;
        for (int coin : coins) {
            int res = helper(coins, rem - coin);
            if (res >= 0) {
                ans = min(ans, 1 + res);
            }
        }
        memo[rem] = (ans == INT_MAX ? -1 : ans);
        return memo[rem];
    }
};