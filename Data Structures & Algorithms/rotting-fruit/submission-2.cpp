class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<pair<int, int>> fruit;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    fruit.push_back({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = 0;
        while (fruit.size()) {
            int size = fruit.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = fruit.front();
                fruit.pop_front();
                for (auto dir : dirs) {
                    int row = x + dir.first;
                    int col = y + dir.second;
                    if (row >= 0 && row < grid.size()
                        && col >= 0 && col < grid[row].size()
                        && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        fruit.push_back({row, col});
                    }
                }
            }
            if (!fruit.size()) break;
            time++;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
