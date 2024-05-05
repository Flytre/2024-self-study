from typing import List
import heapq


class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        capital, profits = zip(*sorted(zip(capital, profits)))
        capital_index, profit_pq = 0, []
        while k > 0:
            while capital_index < len(capital) and w >= capital[capital_index]:
                heapq.heappush(profit_pq, -profits[capital_index])
                capital_index += 1
            if len(profit_pq) == 0:
                break
            w += -heapq.heappop(profit_pq)
            k -= 1
        return w


sol = Solution()
print(sol.findMaximizedCapital(2, 0, [18, 13, 12], [2, 0, 1]))
