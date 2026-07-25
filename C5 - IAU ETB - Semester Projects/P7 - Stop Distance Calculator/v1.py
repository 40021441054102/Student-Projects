def analyzeBraking():
    #info
    try:
        V = input("Enter initial speed (V): ")
        d = input("Enter distance to obstacle (d): ")
        t = input("Enter reaction time (t): ")
        a = input("Enter braking deceleration (a): ")
        V = float(V)
        d = float(d)
        t = float(t)
        a = float(a)
    except ValueError:
        print("bayad adad vared konid")
        return
    # fasele
    dx_reaction = V * t
    # fasele baad az tormoz
    dx_braking = (V ** 2) / (2 * a)
    # masafate kol
    total_stopping_distance = dx_reaction + dx_braking
    print("Masafate vakonesh :", dx_reaction)
    print("Masafate heyne tormoz :", dx_braking)
    print("Masafate kole tormoz :", total_stopping_distance)
    print("Fasele ta mane d :", d)
    #check kardane barkhord
    if total_stopping_distance <= d:
        print("Barkhord nemikonad")
    else:
        print("Barkhord mikonad")
        # total stopping distance bayad barabar ba d bashad
        # d = V_new * t + (V_new^2) / (2 * a)
        # (1 / (2*a)) * V_new^2 + t * V_new - d = 0
        A = 1 / (2 * a)
        B = t
        C = -d
        delta = (B ** 2) - (4 * A * C)
        if delta >= 0:
            V_safe = (-B + (delta ** 0.5)) / (2 * A)
            speed_reduction = V - V_safe
            print("sorat avalie bayad hadaghal", speed_reduction, "kamtar bashad")
            print("sorate amn :", V_safe)
        else:
            print("Moadele pasokh nadarad")


analyzeBraking()
