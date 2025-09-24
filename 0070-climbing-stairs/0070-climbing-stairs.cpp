class Solution {
public:
    vector<int> memo; 

    int climbStairs(int n) {
        memo.assign(n + 1, -1); 
        return helper(n);
    }

    int helper(int n) {
        if (n <= 2) return n;

        if (memo[n] != -1) return memo[n];

        memo[n] = helper(n - 1) + helper(n - 2);
        return memo[n];
    }
};
