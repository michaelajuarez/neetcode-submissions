class Solution {
public:
    vector<vector<int>> retArr;

    void dfs(int index, vector<int>& nums, int target, vector<int>& subset) {
        if (target == 0) {
            retArr.push_back(subset);
            return;
        }
        if (target < 0 or index >= nums.size()) return;
        
        subset.push_back(nums[index]);
        dfs(index, nums, target - nums[index], subset);
        subset.pop_back();
        dfs(index + 1, nums, target, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        dfs(0, nums, target, subset);
        return retArr;
    }
};
