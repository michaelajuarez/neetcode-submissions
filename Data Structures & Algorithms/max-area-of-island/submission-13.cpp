class Solution {
public:
    int area = 0;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x >= grid.size() or x < 0 or y >= grid[x].size() or y < 0 or grid[x][y] == 0) {
            return 0;
        }
        
        grid[x][y] = 0;
        int size = 1;
        for (auto [i, j] : dirs) {
            size += dfs(grid, x + i, y + j);
        }
        return size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                area = max(area, dfs(grid, i, j));
            }
        }
        return area;
    }
};
