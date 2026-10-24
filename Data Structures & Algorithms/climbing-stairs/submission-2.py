class Solution:
    def climbStairs(self, n: int) -> int:
        cache = [-1] * n

        def dfs(i) -> int:
            if i > n:
                return 0
            if i == n:
                return 1
            if cache[i] != -1:
                return cache[i]
                
            retVal = 0
            retVal += dfs(i + 1)
            retVal += dfs(i + 2)
            cache[i] = retVal
            return retVal
        
        return dfs(0)
        