--[[
This Kata is part of 6 part series that will get you acquinted with Lua. At the end of lesson 6, you should be able to attempt or translate any Kata to Lua. If you need to test your code before submitting, go to Lua's official demo here and write tests in the editor and hit "RUN".

In this Kata, we are going to go deeper into Lua's number system and then solve a problem.

Both integers and floats in Lua have type number. Integers in Lua have a safe limit of -2^53 to +2^53, something we also see in Javascript. Lua has all mathematical operators that you will find in other languages. Examples are:

5/2 = 2.5 
5 % 2 = 1 (remainder)
Relational operators work the way you would expect.

2 < 2 = false
2 <= 2 = true
Lua has a number of useful math methods, but nothing you haven't seen before.

math.floor(2.5) = 2
math.ceil(2.5) = 3
math.modf(2.5) = returns two values: 2  0.5. it separates 2.5 into 2 and 0.5. Usage: a,b = math.modf(2.5). Then a is 2, b is 0.5
math.max(2,3,4) = 4; math.min(2,3,4) = 2
math.exp -- raises e to a power
math.log -- natural log), math.log10 --log to base 10
math.pi -- value of pi
math.pow -- raises a number to power
math.abs -- absolute value
math.tointeger(1.0) = 1; math.tointeger(1.1) = nil -- no way to make 1.1 an integer.
etc..
Consider the following code snippet, which approximates the number of digits in factorial(n).

digitsInFact(n) = floor(((n*log10(n/e)+log10(2*pi*n)/2.0))) + 1.

--We apply math methods.

digitsInfact(n) = math.floor(((n * math.log10(n/math.exp(1)) + math.log10(2*math.pi*n)/2.0))) + 1

-- and that's it!
In this Kata, you will be given a number n, and you will perform the following operations:

if n is even: divide by 3 (that is, n/3) -> get floor value -> raise it pow of 3 -> multiply by pi -> return ceil value;
if n is odd: divide by 2 (=>n/2) -> get ceil value -> raise it pow of 2 -> multiply by exp(2) -> return floor value;
From the resulting n, return "max digit of n, sum of digits of n"
You will need variables to keep track of the min, max and the sum. For instance, solve(246) = '7 25'.

More examples in the test cases.

Enough of numbers. In the next lesson, we will look at Strings.
--]]


local function numbers(n)
 if (n % 2 == 0) then
  n = math.ceil(math.floor(n/3)^3 * math.pi);
else
  n = math.floor(math.ceil(n/2)^2 * math.exp(2));
end
print(n)
 local max, suma, digit = 0, 0, 0;
 while( n > 0 ) do
   digit = n % 10;
   suma = suma + digit
   if (max < digit) then max = digit end;
   n = math.floor(n / 10);
 end
 return max .. " " .. suma;
end

print(numbers(245)) ;
