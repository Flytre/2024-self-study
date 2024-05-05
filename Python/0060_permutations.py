import math


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res = ""
        arr = [i for i in range(1, n + 1)]
        k -= 1
        while len(res) < n:
            subgroup_size = math.factorial(n - len(res) - 1)
            subgroup_number = k // subgroup_size
            k -= subgroup_number * subgroup_size
            res += str(arr[subgroup_number])
            del arr[subgroup_number]
        return res

print(Solution().getPermutation(3, 3))