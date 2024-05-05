#!/bin/python3

import math
import os
import random
import re
import sys
from collections import *


#
# Complete the 'getResult' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arrival
#  2. INTEGER_ARRAY direction
#


def getResult(arrival, direction):
    ascending_queue = deque()
    descending_queue = deque()
    previous_action, previous_time = None, -1
    res = [-1] * len(arrival)
    time, index = 0, 0
    while ascending_queue or descending_queue or index < len(arrival):
        while index < len(arrival) and time == arrival[index]:
            if direction[index] == 0:
                ascending_queue.append(index)
            else:
                descending_queue.append(index)
            index += 1
        if not ascending_queue and not descending_queue:
            time = arrival[index]
        else:
            if previous_time + 1 < time:
                previous_action = None
            if previous_action is None or previous_action == "d":
                if descending_queue:
                    i = descending_queue.popleft()
                    res[i] = time
                    previous_action, previous_time = "d", time
                else:
                    i = ascending_queue.popleft()
                    res[i] = time
                    previous_action, previous_time = "a", time
            else:
                if ascending_queue:
                    i = ascending_queue.popleft()
                    res[i] = time
                    previous_action, previous_time = "a", time
                else:
                    i = descending_queue.popleft()
                    res[i] = time
                    previous_action, previous_time = "d", time
            time += 1
    return res

print(getResult([0, 1, 1, 3, 3], [0, 1, 0, 0, 1]))
