"""
Write a function that takes a positive integer and returns the next smaller positive integer containing the same digits.

For example:

next_smaller(21) == 12
next_smaller(531) == 513
next_smaller(2071) == 2017
Return -1 (for Haskell: return Nothing, for Rust: return None), when there is no smaller number that contains the same digits. Also return -1 when the next smaller number with the same digits would require the leading digit to be zero.

next_smaller(9) == -1
next_smaller(135) == -1
next_smaller(1027) == -1  # 0721 is out since we don't write numbers with leading zeros
some tests will include very large numbers.
test data only employs positive integers.
The function you write for this challenge is the inverse of this kata: "Next bigger number with the same digits."
"""


'''
Example explanation:
From a number n = 37124
loop (backward) and find if next number is bigger --> 1<7
get the max from the subList befor the 7 : [1,2,4] --> 4
swap(7 and 4) --> [34127]
sort the new subList, now before the 4 [1,2,7] --> [7,2,1]
merge [3,4] + [1,2,7] --> [3,4,1,2,7]
make int from list --> 34721  --> next smaller
'''


# From a list get the index of maximum value
def get_idx_max(ls):
    if len(ls) == 1: return ls[0]
    return [idx for idx, value in enumerate(ls) if value == max(ls)][0]


# Converts a list of one digit elements into an integer
def list_of_digits_to_int(ls):
    return "".join([str(digit) for digit in ls])


# Works with the digits list reversed, i.e. the
# comparison starts with the lower order numbers.
def next_smaller(n):
    digits = [int(x) for x in str(n)]
    if digits == list(sorted(digits)): return -1

    digits = list(reversed(digits))
    for idx in range(1, len(digits)):
        current = digits[idx]
        prev = digits[idx-1]
        if current > prev:
            tail = digits[:idx]  # from start to prev
            idx_max = get_idx_max(tail)
            # print(idx_max)
            # print(digits[idx_max])
            while current < digits[idx_max]:
                del tail[idx_max]
                if not tail: return -1
                # print(tail)
                idx_max = get_idx_max(tail)
            digits[idx], digits[idx_max] = digits[idx_max], digits[idx]
            answer = list(reversed(digits[idx:])) + list(reversed(sorted(digits[:idx])))
            return list_of_digits_to_int(answer)
    return n


print(f"37124 -> {next_smaller(37124)}")
print(f"37129 -> {next_smaller(37129)}")
# print(f"3712444 -> {next_smaller(3712444)}")
# print(f"1234567908 -> {next_smaller(1234567908)}")
# print(f"2071 -> {next_smaller(2071)}")
print(f"2017 -> {next_smaller(2017)}")
# print(f"2117 -> {next_smaller(2117)}")
# print(f"531 -> {next_smaller(531)}")
# print(f"907 -> {next_smaller(907)}")
# print(f"21 -> {next_smaller(21)}")
# print(f"135 -> {next_smaller(135)}")
# print(f"8 -> {next_smaller(8)}")
