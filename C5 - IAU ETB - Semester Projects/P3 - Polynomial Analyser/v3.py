import math
def solve_quadratic():
    """
    in method zarayeb, delta va nahiye ha ra mohasebe mikonid
    """
    try:
        a = float(input("a ra vared konid: "))
        b = float(input("b ra vared konid: "))
        c = float(input("c ra vared konid: "))
    except ValueError:
        print("Error : bayad adad bashad")
        return
    if a == 0:
        print("Error : a nemitavanad 0 bashad")
        return
    
    delta = b**2 - 4*a*c
    if delta > 0:
        x1 = (-b + math.sqrt(delta)) / (2 * a)
        x2 = (-b - math.sqrt(delta)) / (2 * a)
        roots = [x1, x2]
        print(f"Number of roots: 2 distinct real roots")
        print(f"Roots: x1 = {x1}, x2 = {x2}")
    elif delta == 0:
        x1 = -b / (2 * a)
        roots = [x1]
        print(f"Number of roots: 1 repeated real root")
        print(f"Root: x = {x1}")
    else:
        roots = []
        print("rishe haghighi nadarad")

    if delta >= 0:
        sum_roots = sum(roots)
        print(f"jame rishe ha : {sum_roots}")

    # sahmi
    xv = -b / (2 * a)
    yv = c - (b**2) / (4 * a)

    quadrants = set()
    
    test_points = [0, xv, xv + 2, xv - 2]
    if delta > 0:
        test_points.extend(roots)
    for x in test_points:
        y = a*(x**2) + b*x + c
        if x > 0 and y > 0:
            quadrants.add(1)
        elif x < 0 and y > 0:
            quadrants.add(2)
        elif x < 0 and y < 0:
            quadrants.add(3)
        elif x > 0 and y < 0:
            quadrants.add(4)
        if x == 0 and y > 0:
            quadrants.update([1, 2])
        if x == 0 and y < 0:
            quadrants.update([3, 4])
        if y == 0 and x > 0:
            quadrants.update([1, 4])
        if y == 0 and x < 0:
            quadrants.update([2, 3])
    print("navahi :", quadrants)

solve_quadratic()