"""
Consider a sequence u where u is defined as follows:

1 - The number u(0) = 1 is the first one in u.
2 - For each x in u, then y = 2 * x + 1 and z = 3 * x + 1 must be in u too.
3 - There are no other numbers in u.
Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13, then 7 gives 15 and 22
and so on...

Task:
Given parameter n the function dbl_linear (or dblLinear...) returns the element
u(n) of the ordered (with <) sequence u (so, there are no duplicates).

Example:
dbl_linear(10) should return 22

Note:
Focus attention on efficiency
"""


def double_linear(n):
    i = 0
    lista = [1]
    while i < n:
        y = 2 * lista[i] + 1
        z = y + lista[i]
        lista.append(z)
        if y not in lista:
            lista.append(y)
        i += 1
    lista = sorted(lista)
    for idx, item in enumerate(lista):
        print(f"{idx} : {item}")
        if idx == 100:
            break
    # print(lista[10])
    # print(lista[100])
    # print(lista[6000])
    # print(lista[100000])
    return lista[231]


print(double_linear(3000))
