def getInfo():
    # info
    info = {
        "age": None,
        "height": None,
        "weight": None
    }
    # age
    while True:
        age = input("Write age : ")
        # adade sahih
        age = int(age)
        if age > 18 and age <=120:
            info["age"] = age
            break
        else:
            print("Error : Invalid age")
    # height
    while True:
        height = input("Write height : ")
        # adade ashari
        height = float(height)
        if height > 0.5 and height < 2.5:
            info["height"] = height
            break
        else:
            print("Error : Invalid height")
    # weight
    while True:
        weight = input("Write weight : ")
        weight = float(weight)
        if weight > 20 and weight < 300:
            info["weight"] = weight
            break
        else:
            print("Error : Invalid weight")
    # return
    return info

def calculateBMI():
    info = getInfo()
    bmi = info["weight"] / (info["height"]**2)
    print("BMI :", bmi)
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
    print("BMI status :", status)
    # min max
    min_normal_weight = 18.5 * (info["height"] ** 2)
    max_normal_weight = 25.0 * (info["height"] ** 2)
    if bmi < 18.5:
        print("shoma laghar hastid")
        weight_min = min_normal_weight - info["weight"]
        weight_max = max_normal_weight - info["weight"]
        print("vazne morede niaz baraye afzayeshe vazn, beyne", weight_min, " va", weight_max)
    elif bmi > 25:
        print("shoma chagh hastid")
        weight_min = info["weight"] - max_normal_weight
        weight_max = info["weight"] - min_normal_weight
        print("vazne morede niaz baraye kaheshe vazn, beyne", weight_min, " va", weight_max)
    else:
        print("vazne shoma normal ast")

calculateBMI()