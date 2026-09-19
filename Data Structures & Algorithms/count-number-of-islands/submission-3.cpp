class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int x, int y) {
        deque<pair<int, int>> queue;
        queue.push_back({x, y});
        grid[x][y] = '0';
        while (queue.size()) {
            for (auto [dir_x, dir_y] : dirs) {
                auto [cur_x, cur_y] = queue.front();
                cur_x += dir_x;
                cur_y += dir_y;
                if (cur_x < grid.size() and cur_x >= 0 and cur_y < grid[x].size() and cur_y >= 0 and grid[cur_x][cur_y] == '1') {
                    queue.push_back({cur_x, cur_y});
                    grid[cur_x][cur_y] = '0';
                }
            }
            queue.pop_front();
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
