class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        retArr = []
        string = []

        def dfs(open_count, closed_count):
            if open_count == closed_count == n:
                retArr.append("".join(string))
                return
            if open_count < n:
                string.append('(')
                dfs(open_count + 1, closed_count)
                string.pop()
            if closed_count < open_count:
                string.append(')')
                dfs(open_count, closed_count + 1)
                string.pop()

        dfs(0, 0)
        return retArr
