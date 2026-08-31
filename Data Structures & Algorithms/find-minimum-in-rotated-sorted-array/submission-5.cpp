class Solution {
public:
    int findMin(vector<int> &nums) {
        int front = 0;
        int back = nums.size() - 1;
        int retVal = INT_MAX;

        while (front <= back) {
            int mid = (front + back) / 2;
            retVal = min(retVal, nums[mid]);
            retVal = min(retVal, nums[front]);
            retVal = min(retVal, nums[back]);
            if (nums[front] < nums[mid]) {
                front = mid+1;
            } else {
                back = mid-1;
            }
        }

        return retVal;
    }
};
