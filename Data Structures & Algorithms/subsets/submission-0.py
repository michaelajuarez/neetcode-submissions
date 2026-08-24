class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        retArr = []
        subset = []

        def dfs(i):
            if i >= len(nums):
                retArr.append(subset.copy())
                return
            subset.append(nums[i])
            print(subset)
            dfs(i+1)
            subset.pop()
            dfs(i+1)

        dfs(0)
        return retArr
