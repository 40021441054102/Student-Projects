def calculate_difference():
    """
    in method ekhtelafe jaryan 2 halate seri va movazi ra baresi mikonad
    """
    try:
        E = float(input("E : "))
        r = float(input("r : "))
    except ValueError:
        print("E va r bayad adad bashand")
        return
    # moghavemat ha
    resistors = []
    n = int(input("Tedade moghavemat ha : "))
    if n <= 0:
        print("Tedad bayad bishtar az 0 bashad")
        return
    for i in range(n):
        res = float(input("Moghavemat R{} ra vared konid : ".format(i + 1)))
        if res <= 0:
            print("Moghavemat bayad bishtar az 0 bashad")
            return
        resistors.append(res)

    # Series
    series = sum(resistors)
    # Parallel
    sum_inverse = sum(1.0 / r_val for r_val in resistors)
    parallel = 1.0 / sum_inverse
    i_series = E / (r + series)
    i_parallel = E / (r + parallel)
    current_difference = abs(i_series - i_parallel)
    print("Moghavemate seri :", series, "ohm")
    print("Moghavemate movazi :", parallel, "ohm")
    print("Jaryan seri :", i_series, "A")
    print("Jaryan movazi :", i_parallel, "A")
    print("Ekhtelaf jaryan :", current_difference, "A")

calculate_difference()
