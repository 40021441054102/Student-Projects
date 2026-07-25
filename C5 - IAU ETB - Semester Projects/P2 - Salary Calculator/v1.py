def calculate_tax(taxable_income):
    tax = 0
    if taxable_income > 40:
        bracket_2 = min(taxable_income, 80) - 40
        tax += bracket_2 * 0.10
    if taxable_income > 80:
        bracket_3 = min(taxable_income, 100) - 80
        tax += bracket_3 * 0.15
    if taxable_income > 100:
        bracket_4 = min(taxable_income, 120) - 100
        tax += bracket_4 * 0.20
    if taxable_income > 120:
        bracket_5 = min(taxable_income, 140) - 120
        tax += bracket_5 * 0.25
    if taxable_income > 140:
        bracket_6 = taxable_income - 140
        tax += bracket_6 * 0.30
    return tax

salary = float(input("Hoghooghe nakhales ra vared konid : "))
overtime_hours = float(input("Saate ezafe kari ra vared konid : "))
#---------------------
overtime_pay = overtime_hours * (salary / 150)
total_income = salary + overtime_pay
insurance = salary * 0.07
tax = calculate_tax(total_income)
total_deductions = insurance + tax
net_salary = total_income - total_deductions
#----------------------------
print("Hoghooghe Nakhales :", salary)
print("Pardakhte ezafe kari :", overtime_pay)
print("Kole daryafti :", total_income)
print("Kasri bime 7% : ", insurance)
print("Kasri maliat :", tax)
print("Kole kasri :", total_deductions)
print("Hoghooghe khales :", net_salary)