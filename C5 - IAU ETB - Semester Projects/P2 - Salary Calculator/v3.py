def calculate_tax(income):
    """
    in method tax ra mohasebe mikonad
    """
    if income <= 40:
        return 0
    elif income <= 80:
        return (income - 40) * 0.10
    elif income <= 100:
        return (40 * 0.10 + (income - 80) * 0.15)
    elif income <= 120:
        return (40 * 0.10 + 20 * 0.15 + (income - 100) * 0.20)
    elif income <= 140:
        return (40 * 0.10 + 20 * 0.15 + 20 * 0.20 + (income - 120) * 0.25)
    else:
        return (40 * 0.10 + 20 * 0.15 + 20 * 0.20 + 20 * 0.25 + (income - 140) * 0.30)

salary = float(input("Hoghooghe nakhales ra vared konid: "))
overtime_hours = float(input("Saate ezafe kari ra vared konid: "))
##################################################################
overtime_pay = overtime_hours * (salary / 150)
total_income = salary + overtime_pay
insurance = salary * 0.07
tax = calculate_tax(total_income)
total_deductions = insurance + tax
net_salary = total_income - total_deductions
# results
print("Hoghooghe Nakhales:", salary)
print("Pardakhte Ezafe Kari:", overtime_pay)
print("Kole Daryafti:", total_income)
print("Kasre Bime:", insurance)
print("Kasre Maliat:", tax)
print("Kole Kasri:", total_deductions)
print("Hoghooghe Khales:", net_salary)