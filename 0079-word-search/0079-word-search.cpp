class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int k) {
        int dx[4] = {0, 1, 0, -1}; // row directions
        int dy[4] = {1, 0, -1, 0}; // col directions
        if (k == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        for (int d = 0; d < 4; d++) {
            int nr = i + dx[d];
            int nc = j + dy[d];
            if (dfs(board, word, nr, nc, k + 1)) {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }
};