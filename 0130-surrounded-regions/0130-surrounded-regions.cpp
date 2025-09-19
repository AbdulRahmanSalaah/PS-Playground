class Solution {
    int dx[4] = {0, 1, 0, -1}; // row directions
    int dy[4] = {1, 0, -1, 0}; // col directions
    bool valid(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }
    int n, m;

public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 ||
                    j == m - 1 && board[i][j] == 'O') {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (board[x][y] == 'O') {
                board[x][y] = '@';
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (valid(nx, ny)) {
                        q.push({nx, ny});
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '@')
                    board[i][j] = 'O';
            }
        }
    }
};
