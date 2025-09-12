class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int maxEndJump = 0;
        int curEndJump = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            maxEndJump = max(maxEndJump, i + nums[i]);
            if (i == curEndJump) {
                jumps++;
                curEndJump = maxEndJump;
            }
        }
        return jumps;
    }
};