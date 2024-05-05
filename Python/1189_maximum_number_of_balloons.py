from collections import Counter


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        ctr = Counter(text)
        return min(ctr.get("b", 0), ctr.get("a", 0), ctr.get("l", 0) // 2, ctr.get("o", 0) // 2, ctr.get("n", 0))
