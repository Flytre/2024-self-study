from typing import *
from collections import deque


class Solution:

    def can_take(self, course, prereq_lists, dp):
        if dp[course] is not None:
            return dp[course]
        if len(prereq_lists[course]) == 0:
            dp[course] = True
            return True
        dp[course] = False
        dp[course] = all(self.can_take(pre, prereq_lists, dp) for pre in prereq_lists[course])
        return dp[course]

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # adj_lists[i] indicates the courses you need to take in order to take course i
        prereq_lists = [[] for _ in range(numCourses)]
        for prereq in prerequisites:
            prereq_lists[prereq[0]].append(prereq[1])
        dp = [None] * numCourses
        return all(self.can_take(course, prereq_lists, dp) for course in range(numCourses))


sol = Solution()
print(sol.canFinish(numCourses=2, prerequisites=[[1, 0], [0, 1]]))
