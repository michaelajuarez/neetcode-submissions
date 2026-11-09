class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        hold = set()
        retArr = []
        for i in range(len(nums) - 2):
            f = i + 1
            b = len(nums)-1
            while f < b:
                total = nums[i] + nums[f] + nums[b]
                if total > 0:
                    b -= 1
                elif total < 0:
                    f += 1
                else:
                    cur = (nums[i], nums[f], nums[b])
                    if cur not in hold:
                        retArr.append([nums[i], nums[f], nums[b]])
                        hold.add((nums[i], nums[f], nums[b]))
                    f += 1
                    b -= 1

        return retArr