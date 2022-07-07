"""
Give you an array, like this:

["from 1 to 3","from 2 to 6","from -100 to 0"]
Find out the maximum range, return by an array:

findMaxRange(["from 1 to 3","from 2 to 6","from -100 to 0"])
return:
["from -100 to 0"]
If more than one elements have the maximum range, return them according to the order of the original array.

Input data is always an array. The format of all elements is always "from m to n". The value of from and to can
be an integer or float. These are all possible: m > n or m == n or m < n

Examples
findMaxRange(["from 1 to 3","from 2 to 4","from 1 to 1"])
should return:
["from 1 to 3","from 2 to 4"]

findMaxRange(["from 1 to 10","from 10 to 1","from -1 to -10"])
should return:
["from 1 to 10","from 10 to 1","from -1 to -10"]

findMaxRange(["from 1 to 10","from 10.1 to 1","from -1 to -10"])
should return:
["from 10.1 to 1"]

findMaxRange([]) should return: []
"""
