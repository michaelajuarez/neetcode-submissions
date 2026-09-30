class Solution {
public:
    int maxArea = 0;
    int ROWS = -1;
    int COLS = -1;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS || grid[x][y] != 1) {
            return 0;
        }

        int total = 1;
        grid[x][y] = 0;
        for (auto [i, j] : dirs) {
            total += dfs(grid, x + i, y + j);
        }
        return total;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
