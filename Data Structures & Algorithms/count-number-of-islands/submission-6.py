class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        retVar = 0

        def dfs(x, y):
            if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[x]):
                return
            if grid[x][y] != '1':
                return
            grid[x][y] = 'X'
            dfs(x + 1, y)
            dfs(x - 1, y)
            dfs(x, y + 1)
            dfs(x, y - 1)
            return

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    dfs(i, j)
                    retVar += 1
        
        print(grid)
        return retVar