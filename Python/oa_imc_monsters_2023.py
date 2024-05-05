def pprint(matrix):
    s = [[str(e) for e in row] for row in matrix]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]
    print('\n'.join(table))


from collections import *
import heapq
from typing import *


def in_bounds(r, c, n, m):
    return 0 <= r < n and 0 <= c < m


def neighbors(r, c, n, m):
    return filter(lambda t: in_bounds(t[0], t[1], n, m), [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)])


def findBestPath(n, m, startRow, startColumn, endRow, endColumn, monsterRow, monsterColumn):
    monsters = list(zip(monsterRow, monsterColumn))
    min_dists = tile_min_dist(n, m, monsters)
    res = [[-1 for _ in range(0, m)] for _ in range(0, n)]
    res[startRow][startColumn] = min_dists[startRow][startColumn]
    heap = [(-min_dists[startRow][startColumn], (startRow, startColumn))]
    while heap:
        d, coord = heapq.heappop(heap)
        for neighbor in neighbors(coord[0], coord[1], n, m):
            if res[neighbor[0]][neighbor[1]] == -1:
                neighbor_d: int = min(-d, min_dists[neighbor[0]][neighbor[1]])
                heapq.heappush(heap, (-neighbor_d, neighbor))
                res[neighbor[0]][neighbor[1]] = neighbor_d
                if neighbor[0] == endRow and neighbor[1] == endColumn:
                    return neighbor_d
    return None


def tile_min_dist(n: int, m: int, monsters: List):
    res = [[-1 for _ in range(0, m)] for _ in range(0, n)]
    queue = deque(monsters)
    for monster in monsters:
        res[monster[0]][monster[1]] = 0
    while queue:
        coord = queue.popleft()
        for neighbor in neighbors(coord[0], coord[1], n, m):
            if res[neighbor[0]][neighbor[1]] == -1:
                queue.append(neighbor)
                res[neighbor[0]][neighbor[1]] = res[coord[0]][coord[1]] + 1
    return res


print(findBestPath(5, 3, 1, 1, 4, 2, [0, 2], [2, 2]))
