class Solution:
    def search(self, nums: List[int], target: int) -> int:
        front = 0
        back = len(nums) - 1
        count = 0

        while front <= back:
            mid = (back + front) // 2
            if nums[mid] < target:
                front = mid + 1
            elif nums[mid] > target:
                back = mid - 1
            elif nums[mid] == target:
                return mid
            count += 1

        return -1
