"""
Don't give me five!
In this kata you get the start number and the end number of a region and should return the count of all numbers except numbers with a 5 in it. The start and the end number are both inclusive!

Examples:

1,9 -> 1,2,3,4,6,7,8,9 -> Result 8
4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> Result 12
The result may contain fives. ;-)
The start number will always be smaller than the end number. Both numbers can be also negative!

I'm very curious for your solutions and the way you solve it. Maybe someone of you will find an easy pure mathematics solution.

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have also created other katas. Take a look if you enjoyed this kata!
"""


def dont_give_me_five(start, end):
    total = end - start + 1
    has_five = 0
    for x in range(start, end + 1):
        if (has5(abs(x))):
            total -= 1
            has_five +=1
    print(has_five)
    return total   # amount of numbers


def has5(x):
    while(x != 0):
        if ( x % 10 == 5):
            return True
        x //= 10
    return False


print( f"NO 5s: {dont_give_me_five(1, 90000000000)}" )
# print( f"NO 5s: {dont_give_me_five(-10000, 9350)}" )
# print( f"NO 5s: {dont_give_me_five(-10050, 9540)}" )
# print( f"NO 5s: {dont_give_me_five(-10050, 9350)}" )
# print( f"NO 5s: {dont_give_me_five(-15555, 9350)}" )
# print( f"NO 5s: {dont_give_me_five(-15555, 9355)}" )
# print( f"NO 5s: {dont_give_me_five(-15555, 1555)}" )
# print( f"NO 5s: {dont_give_me_five(-15555, 5555)}" )
# print( f"NO 5s: {dont_give_me_five(1, 66748300 )}" )

