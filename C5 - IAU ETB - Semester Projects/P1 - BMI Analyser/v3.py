def get_age():
    """
    in method sen ra mohasebe mikonad
    """
    while True:
        try:
            age = int(input("Write age : "))
            if 18 < age <= 120:
                return age
            else:
                print("Error : sen eshtebah ast")
        except ValueError:
            print("Error : sen bayad adad bashad")
def get_weight():
    """
    in method vazn ra mohasebe mikonad
    """
    while True:
        try:
            weight = float(input("Write weight : "))
            if 30 < weight < 200:
                return weight
            else:
                print("Error : vazn eshtebah ast")
        except ValueError:
            print("Error : vazn bayad adad bashad")
def get_height():
    """
    in method ghad ra mohasebe mikonad
    """
    while True:
        try:
            height = float(input("Write height : "))
            if 0.3 < height < 3:
                return height
            else:
                print("Error : ghad eshtebah ast")
        except ValueError:
            print("Error : ghad bayad adad bashad")

def analyse_bmi():
    """
    This method analyse BMI
    """
    age = get_age()
    height = get_height()
    weight = get_weight()
    bmi = weight / (height ** 2)
    print("natije :")
    print(" - sen :", age)
    print(" - BMI :", bmi)

    if bmi < 18.5:
        status = "kamtar az normal"
    elif 18.5 <= bmi < 25:
        status = "normal"
    elif 25 <= bmi < 30:
        status = "ezafe vazn"
    elif 30 <= bmi < 35:
        status = "chaghi daraje 1"
    elif 35 <= bmi < 40:
        status = "chaghi daraje 2"
    elif 40 <= bmi <= 50:
        status = "chaghi shadid"
    else:
        status = "chaghi besiar shadid"
    print(" - vaziyat BMI :", status)
    min_weight = 18.5 * (height ** 2)
    max_weight = 25.0 * (height ** 2)
    if bmi < 18.5:
        weight_min = min_weight - weight
        weight_max = max_weight - weight
        print("shoma kambood vazn darid ...")
        print("vazne morede niaz :", weight_min, " -", weight_max, "KG")
    elif bmi > 25:
        weight_min = weight - max_weight
        weight_max = weight - min_weight
        print("shoma ezafe vazn darid ...")
        print("vazne ezafe :", weight_min, " -", weight_max, "KG")
    else:
        print("vazne shoma normal ast")

analyse_bmi()