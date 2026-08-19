class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        if len(s) <= 1:
            return False

        for x in s:
            if x == '(' or x == '{' or x == '[':
                stack.append(x)
            
            if x == ')':
                if not stack or (stack and stack[-1] != '('):
                    return False
                elif stack:
                    stack.pop()
            if x == '}':
                if not stack or (stack and stack[-1] != '{'):
                    return False
                elif stack:
                    stack.pop()
            if x == ']':
                if not stack or (stack and stack[-1] != '['):
                    return False
                elif stack:
                    stack.pop()

        if stack:
            return False
        return True