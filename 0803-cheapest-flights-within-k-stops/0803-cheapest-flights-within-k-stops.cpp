#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // {cost, {node, stops}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int cost = cur.first;
            int node = cur.second.first;
            int stops = cur.second.second;

            if (stops > k) continue;

            for (auto& p : adj[node]) {
                int next = p.first;
                int w = p.second;
                int newCost = cost + w;

                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    q.push({newCost, {next, stops + 1}});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
