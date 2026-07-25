V = input("V : ")
d = input("d : ")
t = input("t : ")
a = input("a : ")
V = float(V)
d = float(d)
t = float(t)
a = float(a)

dx_reaction = V * t
dx_braking = (V ** 2) / (2 * a)
total_stopping_distance = dx_reaction + dx_braking

print("Masafate vakonesh :", dx_reaction)
print("Masafate heyne tormoz :", dx_braking)
print("Masafate kole tormoz :", total_stopping_distance)
print("Fasele ta mane d :", d)

if total_stopping_distance <= d:
    print("Barkhord nemikonad")
else:
    print("Barkhord mikonad")
    # d = V_new * t + (V_new^2) / (2 * a)
    A = 1 / (2 * a)
    B = t
    C = -d
    delta = (B ** 2) - (4 * A * C)
    if delta >= 0:
        V_safe = (-B + (delta ** 0.5)) / (2 * A)
        speed_reduction = V - V_safe
        print("sorat avalie bayad hadaghal", speed_reduction, "kamtar bashad")
    else:
        print("Moadele pasokh nadarad")