class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        prev = self.countAndSay(n - 1)
        prev_dig = prev[0]
        prev_ct = 1
        nxt = ""
        for i in range(1, len(prev)):
            if prev[i] != prev_dig:
                nxt += str(prev_ct) + str(prev_dig)
                prev_dig = prev[i]
                prev_ct = 1
            else:
                prev_ct += 1
        nxt += str(prev_ct) + str(prev_dig)
        return nxt

sol = Solution()
for i in range(1,6):
    print(sol.countAndSay(i))


