import heapq
from typing import List


class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int,
                       end_node: int) -> float:
        adj_m = [[] for _ in range(0, n)]
        for index, edge in enumerate(edges):
            adj_m[edge[1]].append([edge[0], succProb[index]])
            adj_m[edge[0]].append([edge[1], succProb[index]])
        visited = [False] * n
        distances = [0] * n
        distances[start_node] = 1
        next_node_heap = [(-1, start_node)]
        while next_node_heap:
            curr_node = heapq.heappop(next_node_heap)[1]

            if curr_node == end_node:
                return distances[end_node]

            visited[curr_node] = True
            for neighbor, neighbor_prob in adj_m[curr_node]:
                if distances[curr_node] * neighbor_prob > distances[neighbor]:
                    distances[neighbor] = distances[curr_node] * neighbor_prob
                    heapq.heappush(next_node_heap, (- distances[curr_node] * neighbor_prob, neighbor))

        return 0



sol = Solution()
print(sol.maxProbability(n = 6, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start_node = 0, end_node = 5))
