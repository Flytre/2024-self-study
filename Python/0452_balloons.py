from typing import List


class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        end = points[0][1]
        arrows = 1

        for point in sorted(points, key=lambda x: x[1]):
            if point[0] <= end:
                end = min(end, point[1])
            else:
                arrows += 1
                end = point[1]
        return arrows


sol = Solution()
print(sol.findMinArrowShots([[1,2],[3,4],[5,6],[7,8]]))
