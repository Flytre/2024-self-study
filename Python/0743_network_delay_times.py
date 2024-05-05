import heapq
from typing import List, Optional


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj_m = [[] for _ in range(0, n)]
        for time in times:
            adj_m[time[0]-1].append([time[1]-1, time[2]])
        dists: List[Optional[int]] = [None] * n
        dists[k-1] = 0
        pq = [(0, k-1)]
        while pq:
            curr = heapq.heappop(pq)[1]
            for neighbor, neighbor_dist in adj_m[curr]:
                if dists[neighbor] is None or dists[neighbor] > dists[curr] + neighbor_dist:
                    dists[neighbor] = dists[curr] + neighbor_dist
                    heapq.heappush(pq, (dists[neighbor], neighbor))
        return max(dists) if all(map(lambda i: i is not None, dists)) else -1

print(all([0,0,0]))
sol = Solution()
print(sol.networkDelayTime( times = [[1,2,1]], n = 2, k = 2))
