from typing import List
from collections import deque


class Solution:
    def find(self, cluster, node):
        if node == cluster[node]:
            return node
        else:
            cluster[node] = self.find(cluster, cluster[node])
            return cluster[node]

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        cluster = [i for i in range(0, len(edges) + 1)]
        for edge in edges:
            n_0_root = self.find(cluster, edge[0])
            n_1_root = self.find(cluster, edge[1])
            if n_0_root == n_1_root:
                return edge
            cluster[n_0_root] = n_1_root
        return None


sol = Solution()
print(sol.findRedundantConnection(edges=[[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]))
