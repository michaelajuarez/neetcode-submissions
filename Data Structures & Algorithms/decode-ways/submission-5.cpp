class Solution {
public:
    int dfs(string s, int i, unordered_map<int, int>& memo) {
        if (memo.contains(i)) {
            return memo[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int retVar = dfs(s, i+1, memo);
        if (i < s.size()-1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) {
            retVar += dfs(s, i+2, memo);
        }
        memo[i] = retVar;
        return retVar;
    }

    int numDecodings(string s) {
        unordered_map<int, int> memo;
        memo[s.size()] = 1;
        return dfs(s, 0, memo);
    }
};
