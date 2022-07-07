--[[
This Kata is part of 6 part series that will get you acquinted with Lua. At the end of lesson 6, you should be able to attempt or translate any Kata to Lua. If you need to test your code before submitting, go to Lua's official demo here and write tests in the editor hit "RUN".

Lua has a number of string methods. In this Kata, we will explore these in detail. Please note that Lua indexes start at 1.

str = 'coder' -- a string
s = "codewars" -- another string

string.len(s) -- returns 8
#s -- shorter way of getting length, returns 8.
string.rep(s,2) -- replicates s twice. Returns "codewarscodewars"
string.reverse(s) -- reverses a string
string.lower(s) and string.upper(s) --returns lower and upper case respectively.
string.char(97) -- returns 'a'
string.sub(s,1,2) -- returns 'co'. Returns characters 1 to 2, both inclusive. Indices start at 1.
string.find("hello world", "he") -- returns '1  2'. It tells us that "he" appers from index 1 to 2. Lua indexes start at 1.
string.find(s,'de') -- returns 3  4. 'de' is at index 3 to 4
"Result is " .. 5 -- returns "Result is 5". Two dots concatenate values.
Conversion to and from string is easy:

toNumber('123') = 123
tostring(123) = '123'
There aren't many other methods to consider. We will work with these for now.

Consider the following code snippet. It checks if a character in str is in letters and converts that character to uppercase or lowercase.

str = "code"     -- string declaration
letters = "abcd"  -- string declaration
for i = 1, #str do -- start for loop. Range is 1 to length of string. Remember that string.len(str) = str:len() = #str
    c = string.sub(str,i,i)  -- this accesses characters in the string. So c at i = 1 is the letter 'c' in 'code'.
    if string.find(letters,c) then
      print(c,string.lower(c),"found")
    else print(c,string.upper(c),"not found")
    end
end
--This returns:
c    c    found
o    O    not found
d    d    found
e    E    not found

-- Notice that we use string.sub(), string.find(), string.lower() and string.upper() methods.
In this Kata, you will write a function that receives three strings a, b, c and return the following:

if a is a palndrome, return true or false otherwise;
the string b with alternated case; character at index 1 will be lowercase, followed by upper, and so on; Lua indices start with 1.
number of vowels in string c. Vowels are one of "aeiou".
the length of all three strings.
You will need to use several string methods to solve this.

The result look like this, seperated by one space:

solve("aulua","codewars","amanac") = "true cOdEwArS 3 19"
In the next lesson, we will get into data structures.


--]]

local function solve(a, b, c)
    local vowels = 0;
    local leng = 0;
    local v_str = "aeiou";

    local ans = a == a:reverse() and "true " or "false ";

    for i = 1, b:len(), 1 do
        if i % 2 == 1 then
            ans = ans .. string.sub(b, i, i):lower();
        else
            ans = ans .. string.sub(b, i, i):upper();
        end
    end
    for i = 1, c:len(), 1 do ;if (string.find(v_str, string.sub(c, i, i)) ~= nil) then
            vowels = vowels + 1;
        end
    end
    leng = a:len() + b:len() + c:len();
    return ans .. " " .. tostring(vowels) .. " " .. tostring(leng);
end

print(solve("aulua", "codewars", "amanac"))
