import math

def get_abc():
    a = 0
    b = 0
    c = 0
    # get a
    while True:
        a = input("a : ")
        a = float(a)
        if a == 0:
            print("Error, a nemitavanad 0 bashad")
        else:
            break
    # get b
    b = input("b : ")
    b = float(b)
    # get c
    c = input("c : ")
    c = float(c)
    return a, b, c

def analyse_roots(a, b, c):
    delta = b**2 - 4 * a * c
    if delta>0:
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        roots = [x1, x2]
        sum = x1 + x2
        print("rishe ha : 2")
        print("x1 :", x1)
        print("x2 :", x2)
    elif delta==0:
        x1 = -b / (2 * a)
        roots = x1
        sum = x1
        print("rishe ha : 1")
        print("x1 :", x1)
    else:
        print("rishe nadarad (manfi)")
        roots = None
        sum = None
    return delta, roots, sum

a, b, c = get_abc()
delta, roots, sum = analyse_roots(a, b, c)


p_x = -b / (2 * a)
p_y = c - (b**2) / (4 * a)
all_quads = set()
test_points = [0, p_x, p_x + 2, p_y - 2]
if delta > 0:
    test_points.extend(roots)
# test points
for x in test_points:
    y = a*(x**2) + b*x + c
    if x > 0 and y > 0: all_quads.add(1)
    elif x < 0 and y > 0: all_quads.add(2)
    elif x < 0 and y < 0: all_quads.add(3)
    elif x > 0 and y < 0: all_quads.add(4)
    if x == 0 and y > 0: all_quads.update([1, 2])
    if x == 0 and y < 0: all_quads.update([3, 4])
    if y == 0 and x > 0: all_quads.update([1, 4])
    if y == 0 and x < 0: all_quads.update([2, 3])

print("nahiye hayi ke sahmi az an migozarad: ", all_quads)