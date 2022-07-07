"""Given a string of words, you need to find the highest scoring word.

Each letter of a word scores points according to its position in the alphabet: a = 1, b = 2, c = 3 etc.

You need to return the highest scoring word as a string.

If two words score the same, return the word that appears earliest in the original string.

All letters will be lowercase and all inputs will be valid.
"""

def high(x):
    lista = x.split()
    suma, maximo = 0, 0
    for indice, palabra in enumerate(lista):
        for letra in palabra:
            suma += ord(letra)-96
        if (suma > maximo):
            maximo = suma
            indice_max = indice
        suma = 0
    return lista[indice_max]

print(high("aa b"))

"""
# Para estudiar:
def high(x):
    return max(x.split(), key=lambda k: sum(ord(c) - 96 for c in k))




def high(x):
    words=x.split(' ')
    list = []
    for i in words:
        scores = [sum([ord(char) - 96 for char in i])]
        list.append(scores)
    return words[list.index(max(list))]
    """
