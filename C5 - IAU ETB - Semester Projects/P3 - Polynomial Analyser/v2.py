import math
def getCoefficents():
    a = b = c = None
    #--- Get : a
    while True:
        try:
            a = float(input("a : "))
            if a == 0:
                print("Err : a nabayad 0 bashad")
            else:
                break
        except Exception as e:
            print("Err : a bayad adad bashad")
    #--- Get : b
    while True:
        try:
            b = float(input("b : "))
            break
        except Exception as e:
            print("Err : b bayad adad bashad")
    #--- Get : c
    while True:
        try:
            c = float(input("c : "))
            break
        except Exception as e:
            print("Err : c bayad adad bashad")
    return a, b, c

def checkRoots(delta, a, b, c):
    if delta > 0:
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        roots = [x1, x2]
        sum = x1 + x2
        print("rishe ha : 2")
        print("x1 :", x1)
        print("x2 :", x2)
        return roots, sum
    elif delta == 0:
        x1 = -b / (2 * a)
        roots = x1
        sum = x1
        print("rishe ha : 1")
        print("x1 :", x1)
        return roots, sum
    else:
        print("Err : rishe nadarad")
        return None, None

a, b, c = getCoefficents()
delta = b**2 - 4*a*c
roots, sum = checkRoots(delta, a, b, c)

#---- markaz sahmi
p_x = -b / (2 * a)
p_y = c - (b**2) / (4 * a)
all_quads = set()
#---- test points
test_points = [0, p_x, p_x + 2, p_y - 2]
if delta > 0:
    test_points.extend(roots)

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

print("nahiye ha : ", all_quads)