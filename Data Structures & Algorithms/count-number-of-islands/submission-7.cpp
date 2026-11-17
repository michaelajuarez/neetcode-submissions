class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[x].size() || grid[x][y] == '0') {
            return;
        }

        grid[x][y] = '0';
        for (auto [i, j] : dirs) {
            dfs(grid, x + i, y + j);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int retVar = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    retVar++;
                }
            }
        }
        return retVar;
    }
};
