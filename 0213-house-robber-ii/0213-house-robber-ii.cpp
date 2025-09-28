class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return max(helper(vector<int>(nums.begin(), nums.end() - 1)),
                   helper(vector<int>(nums.begin() + 1, nums.end())));
    }

    int helper(vector<int> nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (i == 1) {
                nums[i] = max(nums[i], nums[i - 1]);
            } else {
                nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
            }
        }
        return nums[nums.size() - 1];
    }
};