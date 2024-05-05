import math
from math import sqrt
from typing import List
import heapq
import queue


class Solution:
    def dist(self, point: List[int]):
        return math.sqrt(sum(val ** 2 for val in point))

    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        x = queue.PriorityQueue()
        for point in points:
            x.put((-self.dist(point), point))
        return list(x.get()[1] for __ in range(0, k))


sol = Solution()
print(sol.kClosest([[3, 3], [5, -1], [-2, 4]], 2))
