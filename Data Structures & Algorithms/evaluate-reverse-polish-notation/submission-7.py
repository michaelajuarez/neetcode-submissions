class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for i in range(len(tokens)):
            cur = tokens[i]
            if cur == '+':
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(first + second)
            elif cur == '-':
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(first - second)
            elif cur == '*':
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(first * second)
            elif cur == '/':
                second = int(stack.pop())
                first = int(stack.pop())
                stack.append(int(first / second))
            else:
                stack.append(int(cur))
        
        return stack[0]
            