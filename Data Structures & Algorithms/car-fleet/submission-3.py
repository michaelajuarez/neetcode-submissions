class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        combined = []
        stack = []
        for i in range(len(position)):
            combined.append((position[i], speed[i]))
        combined.sort(reverse=True)
        
        for x in combined:
            current_time = (target - x[0]) / x[1]
            if not stack or current_time > stack[-1]:
                stack.append(current_time)
        
        print(stack)
        return len(stack)