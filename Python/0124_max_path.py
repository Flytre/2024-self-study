from typing import Optional, Tuple


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    greatest_triangle_sum = -100000000

    # returns the greatest linearly progressing sum down a tree from the root
    # i.e. for [1,2,3], 1 + 3 = 4 which is the biggest linearly downward sum.
    def greatest_linear_sum(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return -100000000
        left = self.greatest_linear_sum(root.left)
        right = self.greatest_linear_sum(root.right)
        greatest_sum = root.val + max(0, left, right)
        self.greatest_triangle_sum = max(self.greatest_triangle_sum, root.val + max(left, 0) + max(right, 0))
        return greatest_sum

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.greatest_linear_sum(root)
        return self.greatest_triangle_sum


def to_binary_tree(items):
    if not items:
        return None

    it = iter(items)
    root = TreeNode(next(it))
    q = [root]
    for node in q:
        val = next(it, None)
        if val is not None:
            node.left = TreeNode(val)
            q.append(node.left)
        val = next(it, None)
        if val is not None:
            node.right = TreeNode(val)
            q.append(node.right)
    return root


sol = Solution()
bt = to_binary_tree([5, 4, 8, 11, None, 13, 4, 7, 2, None, None, None, 1])
print(sol.maxPathSum(bt))
