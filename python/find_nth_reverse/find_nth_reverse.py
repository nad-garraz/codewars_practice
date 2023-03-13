"""
DESCRIPTION:
Reverse Number is a number which is the same when reversed.

For example, the first 20 Reverse Numbers are:

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101
TASK:

You need to return the nth reverse number. (Assume that reverse numbers start from 0 as shown in the example.)
NOTES:

1 < n <= 100'000'000'000

"""


def find_reverse_number(n):
    '''
    Tengo que generar los numeros pensando
    en que el mayor número de la mitad para la derecha cambie
    primero.
    De esa manera el número crece lo más lento posible.
    '''
    rev = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    for digit in range(0, how_many_digits(n//2)):
        

def how_many_digits(n):
    return len(str(n))

def is_reversible(n):
    n = 
    for digit in range(0, how_many_digits(n//2)):
        



print(how_many_digits(4433))
