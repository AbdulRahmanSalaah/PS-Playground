class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
    
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty()) {
        auto [time, cell] = pq.top();
        pq.pop();
        int x = cell.first;
        int y = cell.second;
        if (vis[x][y])
            continue;
        vis[x][y] = true;

        if (x == n - 1 && y == n - 1)
            return time;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                int newTime = max(time, grid[nx][ny]);
                if (newTime < dist[nx][ny]) {
                    dist[nx][ny] = newTime;
                    pq.push({newTime, {nx, ny}});
                }
            }
        }
    }
        return -1;
    }
};
