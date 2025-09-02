class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(0, nums, path, res);
        return res;
    }

private:
    void backtrack(int i, vector<int> &nums, vector<int> &path,vector<vector<int>> &res)
     {
        res.push_back(path);
        for (int j = i; j < nums.size(); j++) {
            path.push_back(nums[j]);
            backtrack(j + 1, nums, path, res);
            path.pop_back();
    }
    }
};