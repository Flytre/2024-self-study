from collections import namedtuple, deque
from typing import List, Set  # Only needed for Python versions < 3.9


class Solution:
    # Defining State inside the class
    State = namedtuple('State', ['row', 'col', 'rotated'])

    def minimumMoves(self, grid: List[List[int]]) -> int:

        def valid(r: int, c: int) -> bool:
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]):
                return False
            return grid[r][c] == 0

        def can_go_right(curr: Solution.State):
            if not curr.rotated:
                return valid(curr.row, curr.col + 2)
            else:
                return valid(curr.row, curr.col + 1) and valid(curr.row + 1, curr.col + 1)

        def can_go_down(curr: Solution.State):
            if not curr.rotated:
                return valid(curr.row + 1, curr.col) and valid(curr.row + 1, curr.col + 1)
            else:
                return valid(curr.row + 2, curr.col)

        def can_rotate_cc(curr: Solution.State):
            return not curr.rotated and can_go_down(curr)

        def can_rotate_ccw(curr: Solution.State) -> bool:
            return curr.rotated and can_go_right(curr)

        start = deque()
        start.append((Solution.State(0, 0, False), 0))
        visited: Set[Solution.State] = set()
        visited.add(Solution.State(0, 0, False))

        while len(start) > 0:
            ccoord, cdist = start.popleft()

            if ccoord.row == len(grid) - 1 and ccoord.col == len(grid[0]) - 2 and not ccoord.rotated:
                return cdist

            possible_moves = list()
            if can_go_right(ccoord):
                possible_moves.append(Solution.State(ccoord.row, ccoord.col + 1, ccoord.rotated))
            if can_go_down(ccoord):
                possible_moves.append(Solution.State(ccoord.row + 1, ccoord.col, ccoord.rotated))
            if can_rotate_cc(ccoord):
                possible_moves.append(Solution.State(ccoord.row, ccoord.col, True))
            if can_rotate_ccw(ccoord):
                possible_moves.append(Solution.State(ccoord.row, ccoord.col, False))
            for neighbor in possible_moves:
                if neighbor not in visited:
                    start.append((neighbor, cdist + 1))
                    visited.add(neighbor)
        return -1


sol = Solution()
print(sol.minimumMoves([[0,0,1,1,1,1],
                        [0,0,0,0,1,1],
                        [1,1,0,0,0,1],
                        [1,1,1,0,0,1],
                        [1,1,1,0,0,1],
                        [1,1,1,0,0,0]]))
