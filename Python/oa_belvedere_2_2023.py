# -*- coding: utf-8 -*-
import sys

input_map = {}


def ParseInputs():
    target = ''
    for line in sys.stdin:
        if not target:
            target = line.strip()
        else:
            temp = line.split(',')

            name = str(temp[0])
            price = temp[1]
            numInput = int(temp[2])
            inputProducts = temp[3].strip().split(';') if int(numInput) > 0 else None

            input_map[name] = (price, inputProducts)
    return target


# strategy: recursively calculate the minimum cost of an ingredient by comparing its optimal buying and crafting prices
def dynamic_solve(target, known_product_cost):
    # we've already calculated the minimum cost for this product
    if target in known_product_cost:
        return known_product_cost[target]

    # cost of buying
    min_cost = float('inf') if input_map[target][0] == "null" else float(input_map[target][0])

    # compare to cost of 'crafting' from optimally sourced ingredients
    if input_map[target][1] != None:
        min_cost = min(min_cost, sum([dynamic_solve(product, known_product_cost) for product in input_map[target][1]]))

    # save our calculation and return the minimum cost
    known_product_cost[target] = min_cost
    return min_cost


def MySolution(target_product):
    return dynamic_solve(target_product, dict())


# IMPLEMETNATION HERE

def main():
    target = ParseInputs()
    result = MySolution(target)
    print(format(result, '.2f'))


if __name__ == '__main__':
    main()
