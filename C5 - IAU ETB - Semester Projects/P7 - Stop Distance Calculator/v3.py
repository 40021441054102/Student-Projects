def analyze_braking():
    """
    in mehtod sorate amn va sorate avaliye jadid ra mohasebe mikonad
    """
    try:
        V = input("initial speed (V) ra vared konid : ")
        d = input("distance to obstacle (d) ra vared konid : ")
        t = input("reaction time (t) ra vared konid : ")
        a = input("braking deceleration (a) ra vared konid : ")
        V = float(V)
        d = float(d)
        t = float(t)
        a = float(a)
    except ValueError:
        print("bayad adad vared konid")
        return
    x_reaction = V * t
    x_braking = (V ** 2) / (2 * a)
    total_stopping_distance = x_reaction + x_braking
    print("----------------------------------------")
    print("Masafate vakonesh :", x_reaction)
    print("Masafate heyne tormoz :", x_braking)
    print("Masafate kole tormoz :", total_stopping_distance)
    print("Fasele ta mane d :", d)
    print("----------------------------------------")
    if total_stopping_distance <= d:
        print("Safe")
    else:
        print("Barkhord ba mane !!!")

        A = 1 / (2 * a)
        B = t
        C = -d
        delta = (B ** 2) - (4 * A * C)
        
        if delta >= 0:
            V_safe = (-B + (delta ** 0.5)) / (2 * A)
            speed_reduction = V - V_safe
            print("sorat avalie morede niaz :", speed_reduction, "kamtar")
            print("sorate amn :", V_safe)
        else:
            print("rishe nadarad")

analyze_braking()