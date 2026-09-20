class Solution {
public:
    int ROWS = -1;
    int COLS = -1;
    int inf = 2147483647;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        deque<pair<int, int>> cells;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    cells.push_back({i, j});
                }
            }
        }

        while (cells.size()) {
            auto [x, y] = cells.front();
            cells.pop_front();
            for (auto [dir_x, dir_y] : dirs) {
                int cur_x = x + dir_x;
                int cur_y = y + dir_y;
                if (cur_x >= 0 and cur_x < grid.size() and cur_y >= 0 and cur_y < grid[cur_x].size() and grid[cur_x][cur_y] == inf) {
                    grid[cur_x][cur_y] = grid[x][y] + 1;
                    cells.push_back({cur_x, cur_y});
                }
                // if (cur_x < 0 or cur_x >= grid.size() or cur_y < 0 or cur_y >= grid[x].size() or grid[cur_x][cur_y] != inf) {
                //     continue;
                // }
                // grid[cur_x][cur_y] = grid[x][y] + 1;
                // cells.push_back({cur_x, cur_y});
            }
        }

        return;
    }
};
