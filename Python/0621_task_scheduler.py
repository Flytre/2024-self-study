from typing import List
from collections import Counter, deque
import heapq


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        frequencies = [0] * 26
        for t in tasks:
            frequencies[ord(t) - ord('A')] += 1

        frequencies.sort()
        f_max = frequencies.pop()
        idle_time = (f_max - 1) * n

        while frequencies and idle_time > 0:
            idle_time -= min(f_max - 1, frequencies.pop())

        idle_time = max(0, idle_time)
        return idle_time + len(tasks)


sol = Solution()
print(sol.leastInterval(["A", "A", "A", "B", "B", "B"], 2))
