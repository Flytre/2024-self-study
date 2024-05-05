from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def goodNodesHelper(start: TreeNode, cmax: Optional[int]):
            if start is None:
                return 0
            cmax = start.val if cmax is None else max(cmax, start.val)
            return (1 if start.val >= cmax else 0) \
                + goodNodesHelper(start.left, cmax) \
                + goodNodesHelper(start.right, cmax)

        return goodNodesHelper(root, None)

