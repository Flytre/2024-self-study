from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        if root is None or subRoot is None:
            return root is None and subRoot is None

        return self.exact_match(root, subRoot) \
            or self.isSubtree(root.left, subRoot) \
            or self.isSubtree(root.right, subRoot)

    def exact_match(self, tree1, tree2):
        if tree1 is None or tree2 is None:
            return tree1 is None and tree2 is None

        return tree1.val == tree2.val \
            and self.exact_match(tree1.left, tree2.left) \
            and self.exact_match(tree1.right, tree2.right)
