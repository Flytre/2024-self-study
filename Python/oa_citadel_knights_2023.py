from typing import *
from collections import deque


def in_bounds(m, n, x, y):
    return 0 <= x < n and 0 <= y < m


def next_loc(m, n, x, y):
    return filter(lambda loc: in_bounds(m, n, loc[0], loc[1]),
                  [(x + (1 if i % 4 >= 2 else -1) * (1 if i >= 4 else 2),
                    y + (1 if i % 2 == 1 else -1) * (2 if i >= 4 else 1))
                   for i in range(0, 8)])


def knight_move(m, n, start: Tuple, end: Tuple):
    deltas = dict({(0, 0): 0})
    visited: set = {start}
    queue = deque([(start, 0)])
    while queue:
        pos, dist = queue.popleft()
        delta_key = (abs(pos[0] - start[0]), abs(pos[1] - start[1]))
        if delta_key not in deltas:
            deltas[delta_key] = dist
        visited.add(pos)
        for loc in next_loc(m, n, pos[0], pos[1]):
            d_key_2 = (abs(end[0] - pos[0]), abs(end[1] - pos[1]))
            if d_key_2 in deltas:
                return dist + deltas[d_key_2]
            if loc not in visited:
                queue.append((loc, dist + 1))


print(knight_move(8, 8, start=(1, 1), end=(3, 3)))
