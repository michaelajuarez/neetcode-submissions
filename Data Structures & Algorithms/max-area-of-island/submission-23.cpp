class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void print(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    int bfs(vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> hold;
        hold.push({x, y});
        int area = 0;
        grid[x][y] = 0;
        area++;

        while (!hold.empty()) {
            auto [i, j] = hold.front();
            hold.pop();
            for (auto [a, b] : dirs) {
                int cur_x = i + a;
                int cur_y = j + b;
                if (cur_x < 0 || cur_y < 0 || cur_x >= grid.size() || cur_y >= grid[cur_x].size() || grid[cur_x][cur_y] == 0) {
                    continue;
                }
                area++;
                grid[cur_x][cur_y] = 0;
                hold.push({cur_x, cur_y});
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, bfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
};
