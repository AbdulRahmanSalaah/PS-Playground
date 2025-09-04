class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<string> chess_board(n, string(n, '.'));

        backtrack(0, n, chess_board, res);
        return res;
    }

    void backtrack(int col, int n, vector<string>& chess_board,
                   vector<vector<string>>& res) {

        if (col == n) {
            res.push_back(chess_board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, chess_board, n)) {
                chess_board[row][col] = 'Q';
                backtrack(col + 1, n, chess_board, res);
                chess_board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, vector<string>& board, int n) {
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};