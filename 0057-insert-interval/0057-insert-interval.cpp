class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> res;


        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            // newInterval after this interval -> just push this interval 
            if (end < newInterval[0])
            {
                res.push_back({start, end});
            }
            // newInterval before this interval -> first push newInterval then update it to the old one 
            else if (start > newInterval[1])
            {
                res.push_back(newInterval);
                newInterval = {start, end};
            }
            // overlap 
            else
            {
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], end);
            }
        }
        res.push_back(newInterval);
        return res;

    }
};