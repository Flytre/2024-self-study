import sys
from collections import defaultdict


def formatted(val: float):
    return "{:.2f}".format(val)


# AssetData stored information about the purchases on a specific asset
class AssetData:

    def __init__(self):
        self.moving_avg = 0
        self.total_qty = 0

    def update(self, value: float, quantity: int):
        self.moving_avg = ((self.moving_avg * self.total_qty) + (value * quantity)) / (
                self.total_qty + quantity)
        self.total_qty += quantity


# TradeExecutor takes in requested trades and executes them if the preconditions are met
class TradeExecutor:

    def __init__(self):
        self.trade_data = defaultdict(lambda: AssetData())
        self.max_sequence_number = None

    # return whether the request was successful or not
    def submit_request(self, key, value: float, quantity: int, sequence_num: int) -> bool:
        if self.max_sequence_number is not None and sequence_num < self.max_sequence_number:
            return False
        self.max_sequence_number = sequence_num
        self.trade_data[key].update(value, quantity)
        print(f"{key}: {formatted(self.trade_data[key].moving_avg)}")
        return True


def monitor_trades(executor: TradeExecutor):
    for line in sys.stdin:
        trades = line.split(";")
        for trade in trades:
            key, value, quantity, sequence_num = trade.split(",")
            value, quantity, sequence_num = float(value), int(quantity), int(sequence_num)
            executor.submit_request(key, value, quantity, sequence_num)


monitor_trades(TradeExecutor())
