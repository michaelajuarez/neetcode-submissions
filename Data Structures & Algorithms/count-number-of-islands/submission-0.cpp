class Solution {
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    void bfs(vector<vector<char>>& grid, int r, int c) {
        deque<pair<int, int>> hold;
        grid[r][c] = '0';
        hold.push_back({r, c});
        
        while (hold.size()) {
            pair<int, int> cur = {hold.front().first, hold.front().second};
            for (auto x : dirs) {
                int row = cur.first + x.first;
                int col = cur.second + x.second;
                if (row >= 0 and col >= 0 and row < grid.size() and col < grid[0].size() and grid[row][col] == '1') {
                    hold.push_back({row, col});
                    grid[row][col] = '0';
                }
            }
            hold.pop_front();
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};
