class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end());
        int s = intervals[0][0];
        int e = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int newstart = intervals[i][0];
            int newend = intervals[i][1];
            if(newstart>=e)
            {
                e = newend;
            }
            else
            {
                cnt++;
                e = min (e,newend);
            }
            
        }
        return cnt;
    }
};