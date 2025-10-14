class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1]; 
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k}); // 0 dist to reach the node k
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int w = it.second;
                if (dist[adjnode] > w + dis) {
                    dist[adjnode] = w + dis;
                    pq.push({w + dis, adjnode});
                }
            }
        }

  
        int ans = 0;
        for (int i = 1; i < dist.size(); i++) {
            ans = max(ans, dist[i]);
        }


        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};