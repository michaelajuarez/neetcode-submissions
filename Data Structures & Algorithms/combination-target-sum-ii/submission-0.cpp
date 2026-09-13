class Solution {
public:
    vector<vector<int>> retArr;

    void dfs(vector<int>& candidates, vector<int>& subset, int target, int index) {
        if (target == 0) {
            retArr.push_back(subset);
            return;
        }
        if (index >= candidates.size() or target < 0) {
            return;
        }

        subset.push_back(candidates[index]);
        dfs(candidates, subset, target - candidates[index], index + 1);
        subset.pop_back();

        while ((index + 1) < candidates.size() and candidates[index] == candidates[index + 1]) {
            index++;
        }
        dfs(candidates, subset, target, index + 1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        dfs(candidates, subset, target, 0);
        return retArr;
    }
};
