# We want to know the index of the vowels in a given word, for example, there are two vowels in the word super (the second and fourth letters).
# So given a string "super", we should return a list of [2, 4].


def vowel_indices(word):
    return [ num for num, item in enumerate(word, 1) if item in ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"] ]

l = vowel_indices("ahi valhFUSAPWQEP<MN>COIP")
print(l)
