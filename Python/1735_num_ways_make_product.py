from typing import List, Dict, Tuple


# the bug is that i over-count 2, 2 and 2, 2 as the same. (aka 1, 1 and 1, 1
class Solution:

    def pcalc(self, through: int):
        p = []
        for i in range(2, through + 1):
            fl = False
            for r in p:
                if i % r == 0:
                    fl = True
                    break
            if not fl:
                p.append(i)
        return p

    def ccalc(self):
        mod = 10 ** 9 + 7
        self.combs = [[0] * 33 for _ in range(10050)]

        for j in range(10050):
            self.combs[j][0] = 1

        for n in range(1, 10050):
            for r in range(1, 33):
                self.combs[n][r] = (self.combs[n - 1][r - 1] + self.combs[n - 1][r]) % mod

    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        self.primes = self.pcalc(10000)
        self.ccalc()
        res = []
        for q in queries:
            pf = self.pf(q[1])
            c = 1
            for f in pf:
                c = c * int((self.combs[q[0] + f - 1][f]) % (10 ** 9 + 7))
            res.append((int)(c % (10 ** 9 + 7)))
        return res

    def pf(self, n):
        freq = dict()
        for i in self.primes:
            if n == 1:
                break
            while n % i == 0:
                if i not in freq:
                    freq[i] = 1
                else:
                    freq[i] += 1
                n /= i
        return freq.values()


sol = Solution()
print(sol.waysToFillArray([[4850,1596]]))
