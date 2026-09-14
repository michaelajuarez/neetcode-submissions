class Solution {
public:
    vector<string> retArr;

    void dfs(int n, string& current, int open, int closed) {
        if (open == n and closed == n) {
            retArr.push_back(current);
            return;
        }

        if (open < n) {
            current += "(";
            dfs(n, current, open + 1, closed);
            current.pop_back();
        }

        if (closed < open) {
            current += ")";
            dfs(n, current, open, closed + 1);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string current;
        dfs(n, current, 0, 0);
        return retArr;
    }
};
