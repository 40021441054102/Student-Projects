def calculateDifference():
    # E va r
    try:
        E = float(input("E : "))
        r = float(input("r : "))
    except ValueError:
        print("E va r bayad adad bashand")
        return
    # moghavemat ha
    resistors = []
    try:
        n = int(input("Tedade moghavemat ha : "))
        if n <= 0:
            print("Tedad bayad bishtar az 0 bashad")
            return
        for i in range(n):
            res_val = float(input("Moghavemat R{} ra vared konid : ".format(i + 1)))
            if res_val <= 0:
                print("Moghavemat bayad bishtar az 0 bashad")
                return
            resistors.append(res_val)
    except ValueError:
        print("Adad vared konid")
        return

    # halate seri
    series = sum(resistors)
    # halate movazi
    sum_inverse = sum(1.0 / r_val for r_val in resistors)
    parallel = 1.0 / sum_inverse
    # mohasebe jaryan ba formule I = E / (r + Rt)
    i_series = E / (r + series)
    i_parallel = E / (r + parallel)
    # mohasebe ekhtelafe jaryan
    current_difference = abs(i_series - i_parallel)

    print("Moghavemate seri :", series, "ohms")
    print("Moghavemate movazi :", parallel, "ohms")

    print("Jaryan seri :", i_series, "A")
    print("Jaryan movazi :", i_parallel, "A")

    print("Ekhtelaf jaryan :", current_difference, "A")

calculateDifference()


# 12 0.5 3 2 4 6 
# 24 1 2 10 10
# 5 2 1 5