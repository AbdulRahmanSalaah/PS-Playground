class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }

        int x = nums.size() / 3;

        vector<int> ans;
        for (auto it : mp) {
            if (it.second > x) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};