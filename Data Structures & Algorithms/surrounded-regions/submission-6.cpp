class Solution {
public:
    int ROWS = -1;
    int COLS = -1;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'M';
        for (auto [i, j] : dirs) {
            dfs(board, x + i, y + j);
        }
    }

    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if ((i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
