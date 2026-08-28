class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = [] # pair {elem, index}
        retArr = [0] * len(temperatures)

        for i in range(len(temperatures)):
            while stack and temperatures[i] > stack[-1][0]:
                retArr[stack[-1][1]] = i - stack[-1][1]
                stack.pop()
            stack.append((temperatures[i], i))
        
        return retArr


        