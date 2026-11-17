class Solution {
public:
    vector<vector<int>> retArr;

    void dfs(vector<int>& nums, vector<int>& cur, int i) {
        if (i >= nums.size()) {
            retArr.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, cur, i + 1);
        cur.pop_back();
        dfs(nums, cur, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, cur, 0);
        return retArr;
    }
};
