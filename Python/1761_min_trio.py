# algorithm:
# min degree sum = 5
# 0. adjacency set
# 1. calculate degree of all node
# 2. find min_deg_sum of trios
#    -> for each node try and find a 2 cycle (O(n^2))
# return min_deg_sum - 6
#
from typing import List


class Solution:
    def minTrioDegree(self, n: int, edges: List[List[int]]) -> int:
        min_sum = 1e6

        adj_sets = [set() for i in range(n)]
        keys = set()
        for a, b in edges:
            adj_sets[a - 1].add(b - 1)
            adj_sets[b - 1].add(a - 1)
            keys.add(a - 1)
            keys.add(b - 1)

        s = sorted(keys, key=lambda k: len(adj_sets[k]))

        for n1 in s:
            if len(adj_sets[n1]) >= min_sum / 3:
                break
            for n2 in adj_sets[n1]:
                third = adj_sets[n1].intersection(adj_sets[n2])
                for n3 in third:
                    min_sum = min(min_sum, len(adj_sets[n3]) + len(adj_sets[n2]) + len(adj_sets[n1]))

        return min_sum - 6 if min_sum < 1e6 else -1
