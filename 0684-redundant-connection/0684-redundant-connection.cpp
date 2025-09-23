class Solution {
public:
    vector<int> parent;

    int Find(int x) {
        if (parent[x] != x)
            parent[x] = Find(parent[x]); 
        return parent[x];
    }

    bool Union(int a, int b) {
        int pa = Find(a), pb = Find(b);
        if (pa == pb) return false; 
        parent[pa] = pb;            
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto &e : edges) {
            if (!Union(e[0], e[1])) 
                return e; // first edge that forms a cycle
        }
        return {};
    }
};
