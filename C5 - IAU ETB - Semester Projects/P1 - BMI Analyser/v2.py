age = int(input("Enter your age: "))
while not (18 < age <= 120):
    print("Error: Invalid age (Must be greater than 18)")
    age = int(input("Enter your age: "))
height = float(input("Enter your height in meters: "))
while not (0.5 < height < 2.5):
    print("Error: Invalid height (Must be between 0.5 and 2.5 meters)")
    height = float(input("Enter your height in meters: "))
weight = float(input("Enter your weight in kilograms: "))
while not (20 < weight < 300):
    print("Error: Invalid weight (Must be between 20 and 300 kg)")
    weight = float(input("Enter your weight in kilograms: "))



bmi = weight / (height ** 2)
print("\n--- Analysis Result ---")
print(f"Age: {age}")
print(f"BMI: {bmi:.2f}")



if bmi < 18.5:
    status = "Underweight"
elif 18.5 <= bmi < 25:
    status = "Normal"
elif 25 <= bmi < 30:
    status = "Overweight"
elif 30 <= bmi < 35:
    status = "Obesity Class I"
elif 35 <= bmi < 40:
    status = "Obesity Class II"
elif 40 <= bmi <= 50:
    status = "Severe Obesity"
else:
    status = "Very Severe Obesity"
print(f"BMI Status: {status}")




min_normal_weight = 18.5 * (height ** 2)
max_normal_weight = 25.0 * (height ** 2)
if bmi < 18.5:
    print("You are underweight.")
    weight_min = min_normal_weight - weight
    weight_max = max_normal_weight - weight
    print(f"Weight needed to gain, between {weight_min:.1f} and {weight_max:.1f} kg.")
elif bmi > 25:
    print("You are overweight.")
    weight_min = weight - max_normal_weight
    weight_max = weight - min_normal_weight
    print(f"Weight needed to lose, between {weight_min:.1f} and {weight_max:.1f} kg.")
else:
    print("Your weight is normal.")