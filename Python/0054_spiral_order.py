from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        bounds = [len(matrix[0]) - 1, len(matrix) - 1, 0, 0]
        incr = [-1, -1, 1, 1]
        idx = [1, 0, 1, 0]
        delt = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        pos = [0, 0]
        dir = 0

        t = len(matrix[0]) * len(matrix)
        ret = []
        while t > 0:
            ret.append(matrix[pos[0]][pos[1]])
            if pos[idx[dir]] == bounds[dir]:
                bounds[(dir + 3) % 4] += incr[(dir + 3) % 4]
                dir = (dir + 1) % 4
            pos[0] += delt[dir][0]
            pos[1] += delt[dir][1]
            t -= 1
        return ret


sol = Solution()
print(sol.spiralOrder([[1,2,3,4],[5,6,7,8],[9,10,11,12]]))
