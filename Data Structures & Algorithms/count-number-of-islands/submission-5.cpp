class Solution {
public:
    int retVar = 0;
    int ROWS = -1;
    int COLS = -1;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS || grid[x][y] != '1') {
            return;
        }
        grid[x][y] = '0';
        for (auto [i, j] : dirs) {
            dfs(grid, x + i, y + j);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    retVar++;
                    dfs(grid, i, j);
                }
            }
        }
        return retVar;
    }
};
