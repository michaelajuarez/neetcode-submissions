class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        retArr = []
        subset = []
        nums.sort()

        def dfs(index):
            if index >= len(nums):
                retArr.append(subset.copy())
                return
            subset.append(nums[index])
            dfs(index+1)
            subset.pop()
            while (index+1) < len(nums) and nums[index] == nums[index+1]:
                index += 1
            dfs(index+1)


        dfs(0)
        return retArr