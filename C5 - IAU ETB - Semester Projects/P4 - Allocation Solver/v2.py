money = 2000
items = 150
#gheymat ha
price_w = 80
price_x = 50
price_y = 25
price_z = 10
solutions = []

for w in range(items + 1):
    for x in range(items + 1 - w):
        for y in range(items + 1 - w - x):
            z = items - (w + x + y)
            if (w * price_w + x * price_x + y * price_y + z * price_z) == money:
                solutions.append((w, x, y, z))

print("halat ha :")
for s in solutions:
    print("w : {} | x : {} | y : {} | z : {}".format(s[0], s[1], s[2], s[3]))
print("tedade nahayi :", len(solutions))