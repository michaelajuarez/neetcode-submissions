class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> retArr;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 and nums[i] == nums[i-1]) continue;
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                if (sum < 0) {
                    front++;
                } else if (sum > 0) {
                    back--;
                } else {
                    retArr.push_back({nums[i], nums[front], nums[back]});
                    front++;
                    back--;
                    while (front < back and nums[front] == nums[front-1]) {
                        front++;
                    }
                }
            }
        }
        
        return retArr;
    }
};
