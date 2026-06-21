class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = (l + r) / 2;

            int d = 1;
            int cur = 0;

            for (int i = 0; i < weights.size(); i++) {
                if (cur + weights[i] <= mid) {
                    cur += weights[i];
                } else {
                    d++;
                    cur = weights[i];
                }
            }

            if (d <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};