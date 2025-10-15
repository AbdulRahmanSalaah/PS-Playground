class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        vector<string> result;

        for (auto it : tickets) {
            adj[it[0]].insert(it[1]);
        }
        dfs("JFK", adj, result);

        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(string node, unordered_map<string, multiset<string>>& adj,
             vector<string>& result) {
        while (adj[node].size()) {
            string next = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(next, adj, result);
        }
        result.push_back(node);
    }
};