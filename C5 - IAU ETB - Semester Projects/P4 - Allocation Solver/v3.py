def find_combinations():
    """
    in method tamame halat haye momken ke 4 kala be gheymate 2000 beresad ra baresi mikonad
    """
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

print("w | x | y | z ")
for c in find_combinations():
    print("w : {} - x : {} - y : {} - z : {}".format(c[0], c[1], c[2], c[3]))