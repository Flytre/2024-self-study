from typing import List


class Solution:
    class Board:
        rows: int
        cols: int
        board: List[List[str]]
        contained: set

        def __init__(self, board: List[List[str]]):
            self.rows = len(board)
            self.cols = len(board[0])
            self.board = board
            self.contained = set([board[r][c] for r in range(self.rows) for c in range(self.cols)])

        def out_of_bounds(self, index: int):
            return index < 0 or index >= self.rows * self.cols

        def letter_or_hashtag(self, index: int):
            if self.out_of_bounds(index):
                return "#"
            return self.board[index // self.cols][index % self.cols]

        def right(self, index: int):
            return index + 1 if index % self.cols < self.cols - 1 else -1

        def left(self, index: int):
            return index - 1 if index % self.cols > 0 else -1

        def all_locations_of_letter(self, letter: str):
            return [row * self.cols + col for row in range(self.rows) for col in range(self.cols) if
                    self.board[row][col] == letter]

        def has_word(self, word: str) -> bool:
            start = self.all_locations_of_letter(word[0])
            if len(word) == 1:
                return len(start) > 0
            if any(letter not in self.contained for letter in word):
                return False

            return any(self.recursive_find_word(s, {s}, word[1:]) for s in start)

        def recursive_find_word(self, loc: int, used_locs: set, word: str) -> bool:

            def find_next_location(start: int, indices: set, letter: str):
                locations = [start - self.cols, start + self.cols, self.right(start), self.left(start)]
                return [index for index in locations if
                        index not in indices and self.letter_or_hashtag(index) == letter]

            possibles = find_next_location(loc, used_locs, word[0])

            if len(word) == 1 or len(possibles) == 0:
                return len(possibles) > 0
            for nxt in possibles:
                used_locs.add(nxt)
                if self.recursive_find_word(nxt, used_locs, word[1:]):
                    return True
                used_locs.remove(nxt)

            return False

    def exist(self, board: List[List[str]], word: str) -> bool:
        big_board = Solution.Board(board)
        return big_board.has_word(word)


sol = Solution()
print(sol.exist([["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word="A"))
