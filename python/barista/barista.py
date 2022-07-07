"""
Recibe una lista de números y devuelve
la minima suma de las acumulaciones
"""
def barista(coffees):
    if len(coffees) < 1:
        return 0
    else:
        for i in range(len(coffees)):
            for j in range(len(coffees)):
                if coffees[j] > coffees[i]:
                    temp = coffees[i]
                    coffees[i] = coffees[j]
                    coffees[j] = temp
                else:
                    continue
        espera = 0;
        final =0;
        for i in range(len(coffees)):
            if i == 0 or i == len(coffees):
                espera += coffees[i]
            else:
                espera += coffees[i] + 2
            final += espera
    return final

pedidos = [5,2,1]
espera = barista(pedidos)
print(espera)
