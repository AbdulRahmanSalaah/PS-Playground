class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int sum = 0;
        vector<int> a;
        backtrack(0, candidates, a, sum, target, res);
        return res;
    }

private:
    void backtrack(int i, vector<int>& candidates, vector<int>& a, int& sum,
                   int target, vector<vector<int>>& res) {

        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(a);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            a.push_back(candidates[j]);
            sum += candidates[j];

            backtrack(j, candidates, a, sum, target, res);

            sum -= candidates[j];
            a.pop_back();
        }
    }
};