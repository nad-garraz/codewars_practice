--[[
This Kata is part of 6 part series that will get you acquinted with Lua. At the end of lesson 6, you should be able to attempt or translate any Kata to Lua. If you need to test your code before submitting, go to Lua's official demo here and write tests in the editor and hit "RUN".

In this Kata, we will understand how to use Lua's control structures. We will introduce data structures briefly, but we will cover them in detail later.

Lua has a number of control structures, which include if-statement, while, repeat and for. You must terminate some of them with the end keyword. We shall start with the if-statement.

--one-liners
if a < b then return a end -- 'else' is optional, but 'then` and 'end' are not.
if a < b then return a else return b end 
--multi-line
if a < b then  
 print('a' < 'b') 
elseif (a == b) then 
 print('a' = 'b')
else
 print('a' > 'b')
end 
In Lua, the while statement is structured as follows:

arr = {} -- empty array. We will cover arrays in a lot more detail later
n = 1234

while (n > 0) do
 table.insert(arr,n % 10) -- append last digit to arr
 n = math.floor(n / 10) 
end

-- this returns {4,3,2,1}. 
Compare the while statement to the repeat..until statement. Note here that the action is performed at least once before the condition is checked.

arr = {} 
n = 1234

repeat 
 table.insert(arr,n % 10)
 n = math.floor(n / 10) 
until (n <= 0)  
               -- no 'end' keyword               
--this returns arr = {4,3,2,1}
-- NOTE CAREFULLY that arr[1] = 4. The element at index 1 is 4. Lua indices start at 1. 
If you need to use a counter explicitly, please note that Lua does not support shortcut increments or decrements. You must use:

counter = counter + 1 -- not counter++, or counter+=1
The for loop is straight forwrard.

for i=1,10 do
 print(i) 
 if (i > 7) then 
   break 
 end  -- end the if statement
end  -- end the for-loop
break exits a loop;

There is no continue statement, which would normally skips the remaining statements in the current iteration of a loop and moves control to the top of the loop. But look at the next code snippet carefully:

arr = {}
for i=1,6 do
  if i % 2 == 0 then goto codewars end -- "codewars" is merely a placeholder here, so that "goto" knows where to jump to.
  table.insert(arr,i) -- "goto" skips this line of code
  ::codewars::
end

for k,v in ipairs(arr) do -- we will discuss this for for loop in detail later.
 print(k,v)
end

1     1
2     3
3     5
Time for a quiz.

In this Kata, we will investigate a sequence that is a very close cousin of the Fibonacci sequence. It starts with 1, 1, 3, 5, 9, 15, 25, 41,..., and it is given by the following formula:

a(n) = 2*Fibonacci(n+1) - 1.

Given a number n, return the nth number in this sequence. For example, solve(2) = 3 and solve(6) = 25.

Good luck!
--]]

local function Control_structures(n)
  if (n == 0 or n == 1) then return 1 end;
  local a, b, c, i = 1, 1, 0, 1;
  while (i < n) do
    c = a + b;
    b = a;
    a = c;
    i = i + 1;
  end
  return (2 * a - 1)
end

print(Control_structures(10));
