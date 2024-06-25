val = [max(count, count + 1) if (count := 2) <= i else 0 for i in range(3)]
_, med, _ = val
print(f'med = {med - 1!r}')