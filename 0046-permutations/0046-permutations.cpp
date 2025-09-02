class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0, nums, res);
        return res;
    }

    void backtrack(int i, vector<int>& nums, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[j], nums[i]);
            backtrack(i + 1, nums, res);
            swap(nums[j], nums[i]);
        }
    }
};