from typing import *
from collections import deque
from typing import List, Any


class Solution:
    ordering = []

    def can_take(self, course, prereq_lists, dp):
        if dp[course] is not None:
            return dp[course]
        if len(prereq_lists[course]) == 0:
            dp[course] = True
            self.ordering.append(course)
            return True
        was_none = dp[course] is None
        dp[course] = False
        dp[course] = all(self.can_take(pre, prereq_lists, dp) for pre in prereq_lists[course])
        if was_none:
            self.ordering.append(course)
        return dp[course]

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        ordering = []
        # adj_lists[i] indicates the courses you need to take in order to take course i
        prereq_lists = [[] for _ in range(numCourses)]
        for prereq in prerequisites:
            prereq_lists[prereq[0]].append(prereq[1])
        dp = [None] * numCourses
        return self.ordering if \
            all(self.can_take(course, prereq_lists, dp) for course in range(numCourses)) \
            else []


sol = Solution()
print(sol.findOrder(numCourses=4, prerequisites=[[1, 0], [2, 0], [3, 1], [3, 2]]))
