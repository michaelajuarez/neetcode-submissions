class Solution:
    def trap(self, height: List[int]) -> int:
        prefix = [0] * len(height)
        suffix = [0] * len(height)

        cur_max = 0
        for i in range(len(height)):
            prefix[i] = cur_max
            cur_max = max(cur_max, height[i])
        cur_max = 0
        for i in range(len(height)-1, -1, -1):
            suffix[i] = cur_max
            cur_max = max(cur_max, height[i])
        
        water = 0
        for i in range(len(height)):
            if i > 0 and i < len(height)-1:
                water += (min(prefix[i+1], suffix[i-1]) - height[i])

        return water