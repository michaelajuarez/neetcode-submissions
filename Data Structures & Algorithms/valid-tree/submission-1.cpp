class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_set<int> check;

    bool dfs(int cur, int parent) {
        if (check.contains(cur)) {
            return false;
        }
        check.insert(cur);
        for (int x : adj[cur]) {
            if (x == parent) continue;
            if (!dfs(x, cur)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // if (edges.size() > n - 1) return false;
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        if (!dfs(0, -1)) return false;
        return check.size() == n;
    }
};
