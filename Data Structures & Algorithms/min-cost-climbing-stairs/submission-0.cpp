class Solution {
public:
    vector<int> cache;

    int dfs(int i, vector<int>& cost) {
        int size = cache.size();
        if (i >= size) return 0;
        if (cache[i] != -1) {
            return cache[i];
        }
        cache[i] = cost[i] + min(dfs(i+1, cost), dfs(i+2, cost));
        return cache[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        cache.resize(cost.size(), -1);
        return min(dfs(0, cost), dfs(1, cost));
    }
};
