class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> qs;
        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());
        // Min-heap: {interval_length, interval_end}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> ans(queries.size(), -1);
        int j = 0; 
        for (auto [q, idx] : qs) {
            //  start <= q
            while (j < intervals.size() && intervals[j][0] <= q) {
                int start = intervals[j][0];
                int end = intervals[j][1];
                pq.push({end - start + 1, end});
                j++;
            }
            
            // Remove end < q
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }
            
            if (!pq.empty()) {
                ans[idx] = pq.top().first; 
            }
        }
        return ans;
    }
};