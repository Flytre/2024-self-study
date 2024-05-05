from collections import defaultdict
from collections import deque


class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        char_to_loc = defaultdict(lambda: [])
        for i in range(0, len(ring)):
            char_to_loc[ring[i]].append(i)

        MAX_VALUE = 1e9
        current_index = 0
        # format is offset: min moves required to get here having already clicked key[0..current_index]
        prev_memo = {0: 0}

        while current_index < len(key):
            next_memo = dict()
            for source in prev_memo.keys():
                for target in char_to_loc[key[current_index]]:
                    if target not in next_memo:
                        next_memo[target] = MAX_VALUE
                    next_memo[target] = min(next_memo[target], prev_memo[source] + 1 + self.dist(len(ring), source, target))
            prev_memo = next_memo
            current_index += 1
        return int(min(prev_memo.values()))

    def dist(self, ring_size, a, b):
        forward_dist = b - a if a < b else a - b
        backward_dist = ring_size - forward_dist
        return min(forward_dist, backward_dist)

sol = Solution()
print(sol.findRotateSteps("abcbdebcd", "acbdebca"))
