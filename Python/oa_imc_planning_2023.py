import heapq
from typing import *
from collections import *


def pprint(matrix):
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print('\n'.join(table))


def dist(x1, y1, x2, y2):
    return y2 - y1 + x2 - x1


def in_bounds(r, c, m, n):
    return 0 <= r < m and 0 <= c < n


def neighbors(r, c, m, n):
    return filter(lambda t: in_bounds(t[0], t[1], m, n), [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)])


def tile_min_dist(m: int, n: int, monsters: List):
    res = [[-1 for _ in range(0, n)] for _ in range(0, m)]
    queue = deque(monsters)
    for monster in monsters:
        res[monster[0]][monster[1]] = 0
    while queue:
        coord = queue.popleft()
        for neighbor in neighbors(coord[0], coord[1], m, n):
            if res[neighbor[0]][neighbor[1]] == -1:
                queue.append(neighbor)
                res[neighbor[0]][neighbor[1]] = res[coord[0]][coord[1]] + 1
    return res


def max_dist(m: int, n: int, start: List, end: List, monsters: List):
    min_dists = tile_min_dist(m, n, monsters)
    res = [[-1 for _ in range(0, n)] for _ in range(0, m)]
    res[start[0]][start[1]] = min_dists[start[0]][start[1]]
    heap = [(-res[start[0]][start[1]], (start[0], start[1]))]
    while heap:
        d, coord = heapq.heappop(heap)
        for neighbor in neighbors(coord[0], coord[1], m, n):
            if res[neighbor[0]][neighbor[1]] == -1:
                neighbor_d: int = min(-d, min_dists[neighbor[0]][neighbor[1]])
                heapq.heappush(heap, (-neighbor_d, neighbor))
                res[neighbor[0]][neighbor[1]] = neighbor_d
                if neighbor[0] == end[0] and neighbor[1] == end[1]:
                    return neighbor_d
    return None


monster_test = [[1, 2], [3, 3]]
print(max_dist(5, 5, [0, 0], [4, 4], monster_test))
