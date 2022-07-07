"""
Funcion que toma un número "n" en base 10
y lo convierte a la base "base"
"""

def faulty_odometer(n, base):
    ans = ""
    while( n != 0 ):
        mod = n % base
        if int( mod ):
            ans += str( mod )
        n = int((n - mod) / base)
    return int(ans[::-1])


print(f"Base 10: 2005,  Base 9: {faulty_odometer(2005,9)}")
