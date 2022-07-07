--[[
This Kata is part of 6 part series that will get you acquinted with Lua. At the end of lesson 6, you should be able to attempt or translate any Kata to Lua. If you need to test your code before submitting, go to Lua's official demo here ("https://www.lua.org/cgi-bin/demo") and write tests in the editor hit "RUN".

Lua has only one data structure, called Table. It is an Object that functions as an Array or Set, or Hash all in one. In this Kata, we will focus on Lists. Although it is possible to start with a list index at 0, it is not common practice. Indices should start at 1.

a = {} -- empty list
a[1] = 1  -- insert 1 at index 1. a = {1}
a[2] = "2" -- a = {1,"2"}
a[#a + 1] = 5 -- This appends 5 to the end of the list. a = {1,"2",5} .
table.insert(a,15) -- It appends to end of list. a = {1,"2",5,15) .
table.insert(a,1,25) -- Inserts 25 at index 1. a = {25,1,"2",5,15)
table.remove(a) -- Removes last element. a = {25,1,"2",5)
table.remove(a,1) -- Removes element at index 1. a = {1,"2",5)
a[4] = false -- a = {1,"2",5,false)

--Iterating through the list is simple:
for i = 1,#a do  --recall that #a returns array length
 print(a[i])
end
-- prints
1
2
5
false
There are a few more useful methods for Lua lists:

a = {} -- empty list
table.insert(a,10) -- a = {10} insert one element, so print(table.unpack(a)) prints 10
table.insert(a,20) -- a = {10,20} insertion at end
table.insert(a,1,100) -- a = {100,10,20} insertion at first index, index 1
x = math.min(table.unpack(a)) -- returns 10
table.sort(a) -- a = {10,20,100}
table.unpack(a) -- 10 20 100 (Notice that there are no braces)
print(table.unpack(a)) -- 10 20 100
print(table.concat(a)) -- 1020100
Let's move on to the question of the day:

In this Kata, you be given an array and your task is to return the elements whose value is exceeded by two or more elements in the array.

For example, solve({1,-2,2,3,4}) = 3, because only {1,-2,2} have at at least two elements that are greater than them. 1 is smaller than 2,3,4. Similarly, -2 is the smallest and is exceed by all other elements, and 2 is smaller than 3 and 4. There are a number of ways to solve this. One way is to run two loops and check if an element occurs at least twice and store it in an array.

More examples in the test cases.

Good luck!
--]]


-- Solucion mia
--[[
local function solve(arr)
  table.sort(arr)
  local count = 0;
  local repeated = 1;
  for i = 1, #arr - 2, 1 do
    if (arr[i] == arr[i+1]) then
      repeated = repeated + 1;
    end
    if ( arr[i] < arr[i+1] and arr[i] < arr[i+2] ) then
      count = count + 1 * repeated
      repeated = 1
    end
  end
return count
end
 --]]

-- Solucion para aprender
local function solve2(arr)
  table.sort(arr)
  for i = #arr - 2, 0, -1 do
    if arr[i]~=arr[i+1] then return i end
  end
  return 0
end

print(solve2({11,12,14,16,21,21,21,19,11,7}))
-- 7,11,11,12,14,15,19,21

