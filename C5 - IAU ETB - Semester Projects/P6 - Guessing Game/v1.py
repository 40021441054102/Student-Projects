import random

def Game():
    print("====================")
    print("Be Bazi Khosh Amadid")
    print("====================")
    min_val = 1
    max_val = 100
    secret_number = random.randint(min_val, max_val)
    score = 100
    penalty = 10
    print("yek adad beyne 1 va 100 entekhab konid, emtiaz shoma : 100")
    print("har hadse eshtebah 10 emtiaz kam mikonad")
    while score > 0:
        try:
            guess = int(input("hadse shoma : "))
        except ValueError:
            print("bayad adad vared konid")
            continue
        #check
        if guess == secret_number:
            print("Afarin adad ro dorost entekhab kardi")
            print("Emtiaz shoma :", score)
            break
        else:
            score -= penalty
            if guess < secret_number:
                print("Adad balatar ast")
            else:
                print("Aadad payin tar ast")
            if score > 0:
                print(" - Emtiaz baghi mande :", score)
            else:
                print("Shoma bakhtid, digar emtiazi nadarid")

Game()
