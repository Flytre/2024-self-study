from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def on_leaf(self, tree, call):
        if tree is None:
            return

        if tree.left is None and tree.right is None:
            call(tree)

        self.on_leaf(tree.left, call)
        self.on_leaf(tree.right, call)

    def try_merge(self, leaf, trees, roots):
        if leaf.val not in roots:
            return

        index, tree = roots[leaf.val]
        leaf.left = tree.left
        leaf.right = tree.right
        trees[index] = None

    def make_max_tree(self, node):
        if node is None:
            return -99999
        if node.left is not None:
            node.left.val = self.make_max_tree(node.left)
            node.val = max(node.val, node.left.val)
        if node.right is not None:
            node.right.val = self.make_max_tree(node.right)
            node.val = max(node.val, node.right.val)
        return node.val

    def canMerge(self, trees: List[TreeNode]) -> Optional[TreeNode]:
        roots = {datum[1].val: datum for datum in enumerate(trees)}
        for i in range(0, len(trees)):
            self.on_leaf(trees[i],lambda leaf: self.try_merge(leaf, trees, roots))
        print(len(list(filter(lambda x: x is None, trees))))
        print(trees)

