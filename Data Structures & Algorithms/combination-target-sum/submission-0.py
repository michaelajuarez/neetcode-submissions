class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        retArr = []

        def dfs(i, current, curVal):
            if curVal == target:
                retArr.append(current.copy())
                return
            if i >= len(nums) or curVal > target:
                return
            current.append(nums[i])
            dfs(i, current, curVal + nums[i])
            current.pop()
            dfs(i+1, current, curVal)
                    
        dfs(0, [], 0)
        return retArr