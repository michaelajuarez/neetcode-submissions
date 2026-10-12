class DSU:
    parent = []
    rank = []

    def __init__(self, n: int):
        self.parent = [0] * n
        self.rank = [1] * n

        for i in range(n):
            self.parent[i] = i

    def find(self, node) -> int:
        cur = node
        while cur != self.parent[cur]:
            self.parent[cur] = self.parent[self.parent[cur]]
            cur = self.parent[cur]
        return cur

    def union(self, u, v) -> bool:
        pu = self.find(u)
        pv = self.find(v)
        if pu == pv:
            return False
        self.parent[pv] = pu
        self.rank[pu] += self.rank[pv]
        return True


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        dsu = DSU(n)
        res = n
        for u, v in edges:
            if dsu.union(u, v):
                res -= 1
        return res
