class Solution:
    def search(self, nums: List[int], target: int) -> int:
        front = 0
        back = len(nums) - 1

        while front <= back:
            mid = (back + front) // 2
            print(front, mid, back)
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                front = mid + 1
            else:
                back = mid - 1

        return -1