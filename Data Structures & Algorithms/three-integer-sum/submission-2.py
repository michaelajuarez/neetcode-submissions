class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        retArr = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            f = i + 1
            b = len(nums)-1
            while f < b:
                total = nums[i] + nums[f] + nums[b]
                if total > 0:
                    b -= 1
                elif total < 0:
                    f += 1
                else:
                    retArr.append([nums[i], nums[f], nums[b]])
                    f += 1
                    b -= 1
                    while f < b and nums[f] == nums[f-1]:
                        f += 1

        return retArr