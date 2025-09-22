class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int>order;

        for (auto p : prerequisites) {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt =0;
        while (!q.empty()) {
            int node = q.front();
            order.push_back(node);
            q.pop();
            cnt++;
            for (auto nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if(cnt==numCourses)
        {
            return order;
        }
        return {};
    }
};