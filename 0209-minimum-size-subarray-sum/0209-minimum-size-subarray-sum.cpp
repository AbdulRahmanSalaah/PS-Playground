class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int mnlen = 0;
        int sm = 0;
        int ans = INT_MAX;

        while (r < nums.size()) {
            sm += nums[r];
            while (sm >= target) {
                ans = min(ans, r - l + 1);
                sm -= nums[l];
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};