import random
def guess_game():
    """
    in method bazi ra ejra mikonad
    """
    print("Welcome to Guess the Number Game")
    min_value = 1
    max_value = 1000
    # yek adade random
    number = random.randint(min_value, max_value)
    emtiaz = 1000
    jarime = 25
    print("yek adad beyne 1 va 1000 entekhab konid")
    print("emtiaz shoma : 1000   -   jarime : 25")

    while emtiaz > 0:
        try:
            guess = int(input("Hads : "))
        except ValueError:
            print("Error : bayad adad vared konid")
            continue
        #---- Check number
        if guess == number:
            print("\n" + "="*40)
            print("Adad", number, "ra dorost hads zadid ! emtiaz shoma :", emtiaz)
            break
        else:
            emtiaz -= jarime
            if guess < number:
                print("Adade morede nazar bishtar ast")
            else:
                print("Adade morede nazar kamtar ast")
            if emtiaz > 0:
                print("emtiaz :", emtiaz)
            else:
                print("Shoma bakhtid :'(")
guess_game()
