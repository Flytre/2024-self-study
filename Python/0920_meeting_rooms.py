from typing import List


class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: if a person could attend all meetings
    """

    def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        sort_i = sorted(intervals, key=lambda x: (x.start, x.end))
        for val in range(1, len(sort_i)):
            if sort_i[val].start < sort_i[val - 1].end:
                return False
        return True


sol = Solution()
print(sol.can_attend_meetings([Interval(0, 30), Interval(5, 10), Interval(15, 20)]))
