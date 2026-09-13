class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freqs = {}
        for x in tasks:
            if x not in freqs:
                freqs[x] = 1
            else:
                freqs[x] += 1

        heap = []
        for k, v in freqs.items():
            heapq.heappush(heap, -v)

        time = 0
        queue = deque()
        while queue or heap:
            time += 1

            if not heap:
                time = queue[0][1]
            else:
                cur = heapq.heappop(heap) + 1
                if cur:
                    queue.append([cur, time + n])
            
            if queue and queue[0][1] == time:
                heapq.heappush(heap, queue.popleft()[0])

        return time