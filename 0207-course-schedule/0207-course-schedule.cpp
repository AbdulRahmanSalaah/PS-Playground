class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int course = p[0], pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return count == numCourses;
    }
};
