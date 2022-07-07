"""
    Wikipedia: The Baum–Sweet sequence is an infinite automatic sequence of 0s and 1s defined by the rule:

bn = 1 if the binary representation of n contains no block of consecutive 0s of odd length;
bn = 0 otherwise;

for n ≥ 0.

Define a generator function baum_sweet that sequentially generates the values of this sequence.

Note that the binary representation of 0 used here is not 0 but the empty string ( which does not contain any blocks of consecutive 0s ).
0 = 0 -- 1
1 = 1 -- 1
2 = 10 -- 0
3 = 11 -- 1
4 = 100 -- 1
5 = 101 -- 0
It will be tested for up to 1 000 000 values.
[1,1,0,1,1,0,0,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1
"""



#
# TODO: NO FUNCIONA UNA CHOTA (2022-05-06)
#

def baum_sweet():
    for d in range(0, 1000000):
        if d == 0:
            yield 1
            break
        zero_added = False
        binary = str(format(d, 'b'))
        zero = 0
        for item in binary:
            if ( item == '0' ):
                zero += 1
            else:
                if zero % 2 == 1 and zero_added == False:
                    yield 0
                    zero_added = True
                zero = 0
        if zero % 2 == 1 and zero_added == False:
            yield 0
        elif zero_added == False:
            yield 1

gen = baum_sweet()
print(next(gen))
print(next(gen))
