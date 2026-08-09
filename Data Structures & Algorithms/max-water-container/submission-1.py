class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxWater = 0
        
        front = 0
        back = len(heights) - 1

        while front < back:
            water = (back - front) * min(heights[front], heights[back])
            maxWater = max(maxWater, water)

            if heights[front] < heights[back]:
                front += 1
            else:
                back -=1
        
        return maxWater