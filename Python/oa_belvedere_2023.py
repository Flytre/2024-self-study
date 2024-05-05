import sys
from collections import defaultdict


def format(val):
    return "{:.2f}".format(val)

class AssetData:
    moving_average = 0
    total_quantity = 0

    def update(self, key, value, quantity):
        self.moving_average = ((self.moving_average * self.total_quantity) + (value * quantity)) / (
                self.total_quantity + quantity)
        self.total_quantity += quantity
        print(f"{key}: {format(self.moving_average)}")


class TradeExecutor:
    trade_data = defaultdict(lambda: AssetData())
    max_sequence_number = -1

    def submit_request(self, key, value, quantity, sequence_num):
        if sequence_num < self.max_sequence_number:
            return
        self.max_sequence_number = sequence_num
        self.trade_data[key].update(key, value, quantity)


executor = TradeExecutor()
for line in sys.stdin:
    trades = line.split(";")
    for trade in trades:
        key, value, quantity, sequence_num = trade.split(",")
        value, quantity, sequence_num = float(value), int(quantity), int(sequence_num)
        executor.submit_request(key, value, quantity, sequence_num)