from typing import List


class Solution:
    def is_space_free(self, board: List[str], row: int, col: int) -> bool:
        if any([board[r][col] == 'Q' for r in range(0, row)]):
            return False

        for i in range(1, min(row, col) + 1):
            if board[row - i][col - i] == 'Q':
                return False

        for i in range(1, min(row + 1, len(board) - col)):
            if board[row - i][col + i] == 'Q':
                return False

        return True

    def solveNQueens(self, n: int) -> List[List[str]]:
        board = ['.' * n] * n
        return self.n_queens_recur(board, 0)

    def n_queens_recur(self, board: List[str], row: int) -> List[List[str]]:
        if row == len(board):
            return [[board[row] for row in range(0, len(board))]]

        possibles = []
        for col in range(0, len(board)):
            if self.is_space_free(board, row, col):
                board[row] = board[row][0:col] + 'Q' + board[row][col + 1:]
                possibles += self.n_queens_recur(board, row + 1)
                board[row] = board[row][0:col] + '.' + board[row][col + 1:]

        return possibles


sol = Solution()
print(sol.solveNQueens(4))

