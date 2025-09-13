class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0)
            return false;

        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        while (!mp.empty()) {
            int start = mp.begin()->first;
            for (int i = 0; i < k; i++) {
                if (mp[start + i] == 0) {
                    return false;
                }
                mp[start + i]--;

                if (mp[start + i] < 1) {
                    mp.erase(start + i);
                }
            }
        }

        return true;
    }
};