class Solution {
public:
    bool dfs(string word, int x, int y, int i, set<pair<int, int>>& check, vector<vector<char>>& board) {
        if (x >= board.size() or y >= board[x].size() or x < 0 or y < 0 or check.contains({x, y}) or board[x][y] != word[i]) {
            return false;
        }
        if (i == word.size()-1) return true;
        check.insert({x, y});
        bool res = dfs(word, x+1, y, i+1, check, board) or dfs(word, x-1, y, i+1, check, board) or dfs(word, x, y+1, i+1, check, board) or dfs(word, x, y-1, i+1, check, board);
        check.erase({x, y});
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> check;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(word, i, j, 0, check, board)) return true;
            }
        }

        return false;
    }
};