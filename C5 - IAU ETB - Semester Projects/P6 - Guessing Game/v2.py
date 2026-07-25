import random
min_val = 1
max_val = 100
secret_number = random.randint(min_val, max_val)
score = 250
penalty = 30
print("beyne 1 va 100 entekhab konid")
print("har hadse eshtebah 30 emtiaz kam mikonad")
while score > 0:
    guess = int(input("hadse shoma : "))
    if guess == secret_number:
        print("Afarin dorost hads zadid, emtiaz :", score)
        break
    else:
        score -= penalty
        if guess < secret_number:
            print("Adad bishtar ast")
        else:
            print("Aadad kamtar ast")
        if score > 0:
            print("emtiaz :", score)
        else:
            print("Shoma bakhtid !!!")