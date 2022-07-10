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




# Converts a list of one digit elements into an integer
def list_of_digits_to_int(ls):
    return int("".join([str(digit) for digit in ls]))


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
            tail = list(reversed(sorted(digits[:idx])))  # from start to prev. To get max
            idx_max = 0
            while current <= tail[idx_max]:  # looking for tail_max, but smaller than current
                idx_max += 1
            digits[idx], digits[idx_max] = digits[idx_max], digits[idx]
            answer = list(reversed(digits[idx:])) + list(reversed(sorted(digits[:idx])))
            if answer[0] == 0: return -1  # Number with leading zeroes are not valid
            return list_of_digits_to_int(answer)
    return n


print(f"414 -> {next_smaller(414)}")
print(f"100 -> {next_smaller(100)}")
print(f"101 -> {next_smaller(101)}")
print(f"37124 -> {next_smaller(37124)}")
print(f"37129 -> {next_smaller(37129)}")
print(f"3712444 -> {next_smaller(3712444)}")
print(f"1234567908 -> {next_smaller(1234567908)}")
print(f"2071 -> {next_smaller(2071)}")
print(f"2017 -> {next_smaller(2017)}")
print(f"2117 -> {next_smaller(2117)}")
print(f"531 -> {next_smaller(531)}")
print(f"907 -> {next_smaller(907)}")
print(f"21 -> {next_smaller(21)}")
print(f"135 -> {next_smaller(135)}")
print(f"8 -> {next_smaller(8)}")
