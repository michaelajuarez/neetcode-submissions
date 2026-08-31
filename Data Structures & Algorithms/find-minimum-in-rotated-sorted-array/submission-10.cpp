class Solution {
public:
    int findMin(vector<int> &nums) {
        int front = 0;
        int back = nums.size() - 1;
        int retVal = nums[0];

        while (front <= back) {
            if (nums[front] < nums[back]) {
                retVal = min(retVal, nums[front]);
                break;
            }
            int mid = front + (back - front) / 2;
            retVal = min(retVal, nums[mid]);
            if (nums[front] <= nums[mid]) {
                front = mid+1;
            } else {
                back = mid-1;
            }
        }

        return retVal;
    }
};
