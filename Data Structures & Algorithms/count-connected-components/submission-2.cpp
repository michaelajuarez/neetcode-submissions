class Solution {
public:
    void dfs(int cur, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[cur] = true;
        for (auto x : adj[cur]) {
            if(!visit[x]) {
                dfs(x, adj, visit);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int connections = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                dfs(i, adj, visit);
                connections++;
            }
        }
        return connections;
    }
};
