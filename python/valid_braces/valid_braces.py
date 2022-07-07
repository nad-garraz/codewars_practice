"""
Write a function that takes a string of braces, and determines if the order of the braces is valid. It should return true if the string is valid, and false if it's invalid.

This Kata is similar to the Valid Parentheses Kata, but introduces new characters: brackets [], and curly braces {}. Thanks to @arnedag for the idea!

All input strings will be nonempty, and will only consist of parentheses, brackets and curly braces: ()[]{}.

What is considered Valid?
A string of braces is considered valid if all braces are matched with the correct brace.

Examples
"(){}[]"   =>  True
"([{}])"   =>  True
"(}"       =>  False
"[(])"     =>  False
"[({})](]" =>  False

"""
import re
def valid_braces(string):
    while ( True ):
        old_len = len(string)
        if old_len == 0:
            return True
        string = re.sub("\{\}",'', string)
        string = re.sub("\[\]",'', string)
        string = re.sub("\(\)",'', string)
        if old_len == len(string):
            return False
        print("a")
print( valid_braces("{{{{}}}}([[[[]]]])") )
