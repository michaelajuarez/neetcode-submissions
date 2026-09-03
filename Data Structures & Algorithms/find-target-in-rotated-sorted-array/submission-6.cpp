class Solution {
public:
    int binarySearch(vector<int>& nums, int front, int back, int target) {
        while (front <= back) {
            int mid = front + (back - front) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[front] < target) {
                front = mid + 1;
            } else {
                back = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int front = 0;
        int back = nums.size() - 1;
        int retVar = -1;

        while (front < back) {
            int mid = front + (back - front) / 2;
            if (nums[mid] > nums[back]) {
                front = mid + 1;
            } else {
                back = mid;
            }
        }

        int pivot = front;
        retVar = binarySearch(nums, 0, pivot - 1, target);
        if (retVar == -1) {
            return binarySearch(nums, pivot, nums.size() - 1, target);
        }

        return retVar;
    }
};
