from typing import List

# GIVE UP
class Solution:

    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        adj_m = dict()
        vertices = list()
        for account in accounts:
            for link in range(2, len(account)):
                adj_m[(account[link - 1], account[0])] = adj_m.get((account[link - 1], account[0]), []) + [
                    (account[link], account[0])]
                adj_m[(account[link], account[0])] = adj_m.get((account[link], account[0]), []) + [
                    (account[link - 1], account[0])]
            if len(account) >= 3:
                adj_m[(account[len(account) - 1], account[0])] = adj_m.get((account[len(account) - 1], account[0]), []) + [
                    (account[1], account[0])]
                adj_m[(account[1], account[0])] = adj_m.get((account[1], account[0]), []) + [
                    (account[len(account) - 1], account[0])]
            vertices = vertices + account[1:]
        vertices = list(set(vertices))
        visited = [False] * len(vertices)



sol = Solution()
sol.accountsMerge([["David", "David0@m.co", "David1@m.co"], ["David", "David3@m.co", "David4@m.co"],
                   ["David", "David4@m.co", "David5@m.co"], ["David", "David2@m.co", "David3@m.co"],
                   ["David", "David1@m.co", "David2@m.co"]])
