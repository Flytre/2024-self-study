from collections import deque


class MinStack:
    main_stack: deque
    min_stack: deque

    def __init__(self):
        self.main_stack = deque()
        self.min_stack = deque()

    def push(self, val: int) -> None:
        self.main_stack.append(val)
        if len(self.min_stack) == 0 or self.min_stack[-1] > val:
            self.min_stack.append(val)

    def pop(self) -> None:
        val = self.main_stack.pop()
        if val == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        return self.main_stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


sol = MinStack()
print(sol.push(-1))
print(sol.top())
print(sol.getMin())
