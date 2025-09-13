class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp;
        for (auto it : hand) {
            mp[it]++;
        }
        while (!mp.empty()) {
            int start = mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
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