class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& grid, set<pair<int, int>>& hold, int x, int y) {
        if (hold.contains({x, y})) {
            return;
        }
        hold.insert({x, y});
        for (auto [i, j] : dirs) {
            int row = x + i;
            int col = y + j;
            if (row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size() && grid[row][col] >= grid[x][y]) {
                dfs(grid, hold, row, col);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        vector<vector<int>> retArr;

        for (int c = 0; c < cols; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, rows-1, c);
        }

        for (int r = 0; r < rows; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, cols-1);
        }

        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                if (pacific.contains({i, j}) && atlantic.contains({i, j})) {
                    retArr.push_back({i, j});
                }
            }
        }

        return retArr;
    }
};
