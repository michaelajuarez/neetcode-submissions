class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        int second_slow = 0;
        while (true) {
            second_slow = nums[second_slow];
            slow = nums[slow];
            if (second_slow == slow) return slow;
        }
    }
};
