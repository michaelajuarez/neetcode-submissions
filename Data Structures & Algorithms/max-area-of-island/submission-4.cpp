class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int bfs(vector<vector<int>>& grid, int r, int c) {
        deque<pair<int, int>> hold;
        grid[r][c] = 0;
        hold.push_back({r, c});
        int area = 1;

        while (hold.size()) {
            for (auto x : dirs) {
                int row = hold.front().first + x.first;
                int col = hold.front().second + x.second;
                if (row >= 0 and col >= 0 and row < grid.size() and col < grid[0].size() and grid[row][col] == 1) {
                    area++;
                    hold.push_back({row, col});
                    grid[row][col] = 0;
                }
            }
            hold.pop_front();
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int max_area = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    max_area = max(max_area, bfs(grid, r, c));
                }
            }
        }

        return max_area;
    }
};
