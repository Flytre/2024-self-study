import sys
import heapq


def formatted(val):
    return "{:.2f}".format(val)


buy_market = []  # format: price,qty
sell_market = []  # format -price, qty


def parse_market_state(split, price_to_key_func, market):
    for i in range(0, 6, 2):
        market.append([price_to_key_func(float(split[i + 1])), int(split[i])])
    heapq.heapify(market)


# return Average Fill price (AFP)
# AFP(x+1) = [AFP(x) * Q(x) + q(x+1) * p(x+1)] / Q(x+1)
# where Q(x) = total quantity, q(x) = current quantity, p(x) = current price
def transact(market, qty) -> float:
    assert qty >= 0
    if qty == 0:
        return 0
    if market[0][1] > qty:
        market[0][1] -= qty
        return (qty * abs(market[0][0])) / qty
    else:
        transaction_price, transaction_qty = heapq.heappop(market)
        afp_x = transact(market, qty - transaction_qty)
        return ((afp_x * (qty - transaction_qty)) + (transaction_qty * transaction_price)) / qty


# takes in a risk value and evens it out with a trade with the side effect of printing trade qty and AFP
# returns: roll-over risk
# if risk > 0 we need to sell, if risk < 0 we need to buy
def match_trade(risk) -> float:
    afp = transact(sell_market if risk > 0 else buy_market, abs(int(risk)))
    print(-int(risk), formatted(afp))
    return risk - int(risk)


line_num = 0
running_risk = 0
for line in sys.stdin:
    split = line.split(" ")
    # create market for first two lines
    if line_num == 0:
        parse_market_state(split, lambda k: k, buy_market)
    elif line_num == 1:
        parse_market_state(split, lambda k: -k, sell_market)
    # operate trades on market for remainder of lines
    else:
        qty, risk_per = int(split[0]), float(split[1])
        running_risk += qty * risk_per
        transact(buy_market if qty > 0 else sell_market, abs(qty))
        running_risk = match_trade(running_risk)
    line_num += 1
