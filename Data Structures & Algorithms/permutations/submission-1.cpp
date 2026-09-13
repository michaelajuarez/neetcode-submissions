class Solution {
public:
    vector<vector<int>> retArr;

    void dfs(vector<int>& nums, vector<int>& subset, vector<bool>& check) {
        if (subset.size() == nums.size()) {
            retArr.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (check[i] == false) {
                check[i] = true;
                subset.push_back(nums[i]);
                dfs(nums, subset, check);
                check[i] = false;
                subset.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> num_check(nums.size(), false);
        vector<int> subset;
        dfs(nums, subset, num_check);
        return retArr;
    }
};
