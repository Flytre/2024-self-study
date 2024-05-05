from typing import *
from collections import defaultdict


# four
# line
# dfs:
#
# for neighbor in neighbors
#     if not visited
#         // condition
#         dfs(neighbor)
# return -1


# W I P
class Solution:
    def get_ratio(self, ratios: defaultdict, curr, target, visited):
        visited[curr] = True
        for neighbor, val in ratios[curr]:
            if neighbor == target:
                return val
            if not visited[neighbor]:
                check = self.get_ratio(ratios, neighbor, target, visited)
                if check != -1:
                    return val * check
        return -1

    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        ratios = defaultdict(lambda: [])
        for i in range(len(equations)):
            ratios[equations[i][0]].append([equations[i][1], values[i]])
            # a /b = values[i]
            if values[i] != 0:
                ratios[equations[i][1]].append([equations[i][0], 1 / values[i]])
            # if values[i] != 0, b/a = 1/values[i]
        return [self.get_ratio(ratios, query[0], query[1], defaultdict(lambda: False)) for query in queries]


sol = Solution()
print(sol.calcEquation(equations=[["a", "b"], ["b", "c"]], values=[2.0, 3.0],
                       queries=[["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]))
