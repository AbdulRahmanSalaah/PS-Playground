class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        st.insert(nums.begin(), nums.end());
        if(st.size()==nums.size())
            return false;
        return true;
    }
};