import sys
from collections import deque

# import numpy as np
# import pandas as pd
# from sklearn import ...

outputs = {"}": "{", "]": "[", ")": "("}

for line in sys.stdin:
    for char in line:
        if char in outputs.values():
            deque.append("test")
        elif char in outputs.keys():
            if deque.count() == 0 or deque.pop() != output[char]:
                print("invalid")
                exit(0)
print("valid" if deque.count() == 0 else "invalid")


