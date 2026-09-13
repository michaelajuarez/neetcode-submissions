class Solution {
public:
    vector<vector<int>> retArr;

    void dfs(vector<int>& nums, vector<int>& subset, int index) {
        if (index >= nums.size()) {
            retArr.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums, subset, index + 1);
        subset.pop_back();
        dfs(nums, subset, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        dfs(nums, subset, 0);
        return retArr;
    }
};
