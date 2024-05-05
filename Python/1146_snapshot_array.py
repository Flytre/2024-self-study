from typing import Tuple, List
import bisect


class SnapshotArray:
    class SnapshotElt:
        def __init__(self):
            self.past: List[Tuple[int, int]] = [(0, 0)]

        def set(self, val: int, snap_id: int):
            if self.past[-1][1] == snap_id:
                self.past[-1] = (val, snap_id)
            else:
                self.past.append((val, snap_id))

        def get(self, snap_id: int):
            index = bisect.bisect_left(self.past, snap_id, key=lambda x: x[1])
            if index == len(self.past) or self.past[index][1] != snap_id:
                index -= 1
            return self.past[index][0]

    def __init__(self, length: int):
        self.data = [self.SnapshotElt() for _ in range(0, length)]
        self.snap_id = -1

    def set(self, index: int, val: int) -> None:
        self.data[index].set(val, self.snap_id + 1)

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id

    def get(self, index: int, snap_id: int) -> int:
        return self.data[index].get(snap_id)


obj = SnapshotArray(3)
obj.set(1,6)
obj.snap()
obj.snap()
obj.set(1,19)
obj.set(0,4)
print(obj.get(0,1))
