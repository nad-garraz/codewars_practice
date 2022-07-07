--[[
--This Kata is part of 6 part series that will get you acquinted with Lua. At the end of lesson 6, you should be able to attempt or translate any Kata to Lua. If you need to test your code before submitting, go to Lua's official demo here and write tests in the editor hit "RUN".

You already know that Lua has only one data structure, called Table. It can also work as a Hash, and this is the the subject of this Kata.

a = {} -- empty list
a[1] = 1  -- insert 1 at index 1. a = {1}
a[2] = "2" -- a = {1,"2"}
a[#a + 1] = 5 -- This appends 5 to the end of the list. a = {1,"2",5} .
table.insert(a,15) -- It appends to end of list. a = {1,"2",5,15)
table.insert(a,1,25) -- Inserts 25 at index 1. a = {25,1,"2",5,15)
table.remove(a) -- Removes last element. a = {25,1,"2",5)
table.remove(a,1) -- Removes element at index 1. a = {1,"2",5)
a[4] = false -- a = {1,"2",5,false)

--Iterating through the Hash is simple:

for k,v in ipairs(a) do -- using the ipairs iterator.
 print(k,v)
end
prints
1    1
2    2
3    5
4    false

for idx = 1, #a do -- recall that #a returns the length of the array.
 print(idx, a[idx])
end
--prints
1    1
2    2
3    5
4    false
All methods we have seen in the Lesson 5: Arrays are applicable here.

Let's move on to the question of the day:

In this Kata, you will be given an array of unique integers within a given range, but 4 numbers will be missing. Your task will be to find the missing numbers. The largest number in the list will be the upper limit, and the lowest will be 1. For instance:

solve({2,3,5,6,9,10} = {1,4,7,8}
Since 10 is the upper limit, the 4 missing numbers must be 1,4,7,8 so that we end up with a complete set of numbers 1 to 10.
Create a Hash from 1 to n and mark the numbers that appear in the question array. Whatever indices remain unmarked are your answer.

Good luck!
--]]

local function LuaArrays(arr)
  local ans = {}
  local j = 1
  table.sort(arr)
  local max_of_arr = arr[#arr]
-- next time use directly arr[#arr] in the loop
  for i = 1, max_of_arr, 1 do
    if not (i == arr[j]) then
      table.insert(ans, i)
    else
      j = j + 1
    end
  end
  return ans
end

local tabla = LuaArrays({ 2, 3, 5, 6, 9, 10 })
for _, nums in ipairs(tabla) do
  print(nums)
end
