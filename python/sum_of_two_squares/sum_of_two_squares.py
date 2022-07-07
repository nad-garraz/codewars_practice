"""
Complete the function that takes a non-negative integer, and returns a list of non-negative integer pairs whose values - when squared - sum to the given integer.

For example, given the parameter 25, the function should return the two pairs [0, 5] and [3, 4] because 0^2 + 5^2 = 25 and 3^2 + 4^2 = 25.

Return the pairs in ascending order, so e.g. [[0, 5], [3, 4]] not [[5, 0], [3, 4]] or [[3, 4], [0, 5]], etc.

If the given value cannot be expressed as the sum of two squares, return an empty array.

Note: The upper bound of the parameter value will be 2,147,483,647

Examples
  0  -->  [ [0, 0] ]
  1  -->  [ [0, 1] ]
  2  -->  [ [1, 1] ]
  3  -->  []
  4  -->  [ [0, 2] ]
  5  -->  [ [1, 2] ]
 25  -->  [ [0, 5], [3, 4] ]
325  -->  [ [1, 18], [6, 17], [10, 15] ]
"""

import math as m

def all_squared_pairs(n):
    l = []
    for f in range(0, m.floor(m.sqrt(n))+1):
        s = m.sqrt( n - f**2 )
        if ( int(s) == s and f <= s):
            l.append([f, round(s)])
    return l

for i in range (310, 326):
    print(f"i: {i} --> {all_squared_pairs(i)}")

