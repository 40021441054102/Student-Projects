def calculate_tax(income):
    tax = 0
    brackets = [
        (40, 0.00),
        (80, 0.10),
        (100, 0.15),
        (120, 0.20),
        (140, 0.25),
    ]
    previous_limit = 0
    for limit, rate in brackets:
        if income > previous_limit:
            amount = min(income, limit) - previous_limit
            tax += amount * rate
        previous_limit = limit
    if income > 140:
        tax += (income - 140) * 0.30
    return tax
# -- Get User Info
salary = float(input("Hoghooghe nakhales ra vared konid: "))
overtime_hours = float(input("Saate ezafe kari ra vared konid: "))
# -- Calculations
overtime_pay = overtime_hours * (salary / 150)
total_income = salary + overtime_pay
insurance = salary * 0.07
tax = calculate_tax(total_income)
total_deductions = insurance + tax
net_salary = total_income - total_deductions

print("\n----- Gozaresh Hoghoogh -----")
print("Hoghooghe Nakhales:", salary)
print("Pardakhte Ezafe Kari:", overtime_pay)
print("Kole Daryafti:", total_income)
print("Kasre Bime 7%:", insurance)
print("Kasre Maliat:", tax)
print("Kole Kasri:", total_deductions)
print("Hoghooghe Khales:", net_salary)