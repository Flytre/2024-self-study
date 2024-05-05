# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None

        nodes = dict()

        def recur(n: 'Node') -> 'Node':
            if n.val in nodes.keys():
                return nodes[n.val]
            copy = nodes[n.val] = Node(n.val)
            copy.neighbors = [recur(nb) for nb in n.neighbors]
            return copy

        return recur(node)


one = Node(val=1)
two = Node(val=2)
three = Node(val=3)
four = Node(val=4)
one.neighbors = [two, four]
two.neighbors = [one, three]
three.neighbors = [two, four]
four.neighbors = [one, three]
sol = Solution()
val = sol.cloneGraph(one)
x = 1
