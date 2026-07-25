def findCombinations():
    budget = 2000
    total_items = 150
    price_w = 80
    price_x = 50
    price_y = 25
    price_z = 10
    solutions = []
    # w
    for w in range(total_items + 1):
        # x
        for x in range(total_items + 1 - w):
            # y
            for y in range(total_items + 1 - w - x):
                # z
                z = total_items - (w + x + y)
                if (w * price_w + x * price_x + y * price_y + z * price_z) == budget:
                    solutions.append((w, x, y, z))
    return solutions
results = findCombinations()

print("w | x | y | z ")
for i in results:
    print(i)