from typing import *


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        res = []
        for interval in intervals:
            if len(res) == 0:
                res.append(interval)
            elif interval[0] <= res[-1][1]:
                res[-1][1] = max(interval[1], res[-1][1])
            else:
                res.append(interval)
        return res


sol = Solution()
print(sol.merge(intervals=[[1, 3], [2, 6], [8, 10], [15, 18]]))
