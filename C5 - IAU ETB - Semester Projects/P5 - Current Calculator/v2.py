E = float(input("E ra vared konid : "))
r = float(input("r ra vared konid : "))


resistors = []
n = int(input("Tedade moghavemat ha : "))
if n <= 0:
    print("Tedad bayad bishtar az 0 bashad")
for i in range(n):
    res_val = float(input("Moghavemat R{} ra vared konid : ".format(i + 1)))
    if res_val <= 0:
        print("Moghavemat bayad bishtar az 0 bashad")
    resistors.append(res_val)


series = sum(resistors)
sum_inverse = sum(1.0 / r_val for r_val in resistors)
parallel = 1.0 / sum_inverse
i_series = E / (r + series)
i_parallel = E / (r + parallel)
difference = abs(i_series - i_parallel)


print("R seri :", series, "ohm")
print("R movazi :", parallel, "ohm")
print("I seri :", i_series, "A")
print("I movazi :", i_parallel, "A")
print("delta I :", difference, "A")