n = int(input("Enter n: "))
result = 0.0
sign = -1
num = 7
prime_index = 0

while True:
    is_prime = True
    if num < 2:
        is_prime = False
    else:
        i = 2
        while i * i <= num:
            if num % i == 0:
                is_prime = False
                break
            i += 1
    if is_prime:
        if prime_index % 2 == 0:
            #-------
            power = num**num
            #-------
            fact = 1
            for i in range(1, num + 1):
                fact *= i
            #-------
            term = power / fact
            result += sign * term
            sign *= -1
            if num == n:
                break
        prime_index += 1
    num += 1
print("Result :", result)

# 7 
# 13
# 19
# 29
# 37
# 43
# 53
# 61