class Solution {
public:
    vector<int> cache;

    int dfs(int i, int n) {
        if (i == n) {
            return 1;
        }
        if (i > n) {
            return 0;
        }
        
        if (cache[i] != -1) {
            return cache[i];
        }

        return cache[i] = dfs(i+1, n) + dfs(i+2, n);
    }

    int climbStairs(int n) {
        for (int i = 0; i < n; i++) {
            cache.push_back(-1);
        }
        return dfs(0, n);
    }
};
