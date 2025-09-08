class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (auto interval : intervals) {
            int s = interval[0];
            int e = interval[1];
            int lastend = res.back()[1];
            if (s <= lastend) {
                res.back()[1] = max(res.back()[1], e);
            } else {
                res.push_back({s, e});
            }
        }
        return res;
    }
};