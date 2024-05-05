from typing import List


class Solution:

    def is_space_free(self, board: List[List[str]], row: int, col: int) -> bool:
        if any([board[r][col] == 'Q' for r in range(0, row)]):
            return False

        for i in range(1, min(row, col) + 1):
            if board[row - i][col - i] == 'Q':
                return False

        for i in range(1, min(row + 1, len(board) - col)):
            if board[row - i][col + i] == 'Q':
                return False

        return True

    def totalNQueens(self, n: int) -> int:
        return self.n_queens_recur([['.'] * n for __ in range(0, n)], 0)

    def n_queens_recur(self, board: List[List[str]], row: int) -> int:
        if row == len(board):
            return 1

        possibles = 0
        for col in range(0, len(board)):
            if self.is_space_free(board, row, col):
                board[row][col] = 'Q'
                possibles += self.n_queens_recur(board, row + 1)
                board[row][col] = '.'

        return possibles


sol = Solution()
print(sol.totalNQueens(1))
