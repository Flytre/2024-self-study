from typing import *
import heapq


# 855. Exam Room
# Medium
# There is an exam room with n seats in a single row labeled from 0 to n - 1.
#
# When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.
#
# Design a class that simulates the mentioned exam room.
#
# Implement the ExamRoom class:
#
# ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
# int seat() Returns the label of the seat at which the next student will set.
# void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.

# Examples n =5:
# [0, 2]: Distance to next seat would be 3
# [3,4]: Distance to next seat would be 2
# [2,4]: Distance to next seat would be 2

class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.ivs = [[-n, 0, n - 1]]

    # return (dist, seat #, split)
    def dist(self, iv: List) -> Tuple[int, int]:
        if iv[0] == 0:
            return iv[1] + 1, 0
        if iv[1] == self.n - 1:
            return self.n - iv[0], self.n - 1
        return (iv[1] - iv[0]) // 2 + 1, (iv[1] - iv[0]) // 2 + iv[0]

    def split(self, iv: List):
        if iv[0] == 0:
            return [[1, iv[1]]]
        if iv[1] == self.n - 1:
            return [[iv[0], self.n - 2]]
        if iv[0] == iv[1]:
            return []
        res = []
        ctr = (iv[1] - iv[0]) // 2 + iv[0]
        if ctr > iv[0]:
            res.append([iv[0], ctr - 1])
        if ctr < iv[1]:
            res.append([ctr + 1, iv[1]])
        return res

    def seat(self) -> int:
        iv = heapq.heappop(self.ivs)
        _, num = self.dist([iv[1], iv[2]])
        splits = self.split([iv[1], iv[2]])
        for split in splits:
            d, _ = self.dist(split)
            heapq.heappush(self.ivs, [-d, split[0], split[1]])
        return num

    # keep track of the adjacent intervals on either side, then merge them / create new one
    # if both sides filled, create new interval
    # if both sides empty, merge left/right intervals
    # if left side empty, merge into left side
    # if right side empty, merge into right side
    def leave(self, p: int) -> None:
        left, right = None, None
        for iv in self.ivs:
            if iv[2] == p - 1:
                left = iv
            if iv[1] == p + 1:
                right = iv
        if left is not None and right is not None:  # empty seats both sides
            self.ivs.append([-self.dist([left[1], right[2]])[0], left[1], right[2]])
            self.ivs.remove(left)
            self.ivs.remove(right)
            heapq.heapify(self.ivs)
        elif left is None and right is None:  # filled seats both sides
            heapq.heappush(self.ivs, [-self.dist([p, p])[0], p, p])
        elif left is None and right is not None:  # empty seat to right
            self.ivs.append([-self.dist([p, right[2]])[0], p, right[2]])
            self.ivs.remove(right)
            heapq.heapify(self.ivs)
        elif left is not None and right is None:
            self.ivs.append([-self.dist([left[1], p])[0], left[1], p])
            self.ivs.remove(left)
            heapq.heapify(self.ivs)
        else:
            assert False


e = ExamRoom(7)
for i in range(0,7):
    e.seat()
print(e.ivs)
e.leave(2)
e.leave(3)
e.leave(4)
print(e.ivs)
e.seat()
print(e.ivs)