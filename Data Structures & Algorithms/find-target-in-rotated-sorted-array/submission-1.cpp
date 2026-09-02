class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() - 1;

        while (front < back) {
            int middle = (front + back) / 2;
            if (nums[middle] > nums[back]) {
                front = middle + 1;
            } else {
                back = middle;
            }
        }

        int pivot = front;

        int result = binarySearch(nums, target, 0, pivot - 1);
        if (result != -1) {
            return result;
        }

        return binarySearch(nums, target, pivot, nums.size() - 1);
    }
};
