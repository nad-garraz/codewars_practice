"""
Task
You are given a car odometer which displays the miles traveled as an integer.

The odometer has a defect, however: it proceeds from digit 3 to digit 5 always skipping the digit 4. This defect shows up in all positions (ones, tens, hundreds, etc).

For example, if the odometer displays 15339 and the car travels another mile, the odometer changes to 15350 (instead of 15340).

Your task is to calculate the real distance, according The number the odometer shows.

Example
For n = 13 the output should be 12(4 skipped).

For n = 15 the output should be 13(4 and 14 skipped).

For n = 2003 the output should be 1461.

Input/Output
[input] integer n
The number the odometer shows.

1 <= n <= 999.999.999

[output] an integer
The real distance.
"""


# def faulty_odometer(n):
#     dif = 0
#     for i in range(1, n+1):
#       if str(i).find('4') != -1:
#         dif += 1
#     print(f"i: {i}, dif: {dif}")
#     # print(f"O.Bien: {i}, Dif: {dif}, Real: {n - dif}")
#     return n - dif
#     list_four = [num for num in range(3, n+1) if (str(num).find('4') != -1)]
#     return n - len(list_four)


def faulty_odometer(n):
    result = 0  # initialize result

    # One by one compute sum of digits
    # in every number from 1 to n
    for x in range(1, n + 1):
        if has4(x):
            result += 1
    return n - result

# A utility function to compute sum
# of digits in a given number x

def has4(x):
    while (x != 0):
        if (x % 10 == 4):
            return True
        x = x // 10
    return False

print(f"{faulty_odometer(2003)}")
