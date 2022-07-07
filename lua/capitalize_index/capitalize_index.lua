--[[
Given a string and an array of integers representing indices, capitalize all letters at the given indices.

For example:

capitalize("abcdef",[1,2,5]) = "aBCdeF"
capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
The input will be a lowercase string with no spaces and an array of digits.

Good luck!

Be sure to also try:

Alternate capitalization

String array revisal
--]]


local function capitalize(s, arr)
  local ans = "";
  local done = false;
  for i = 1, #s, 1 do
  done = false
    for j = 1, #arr, 1 do
      if (i == arr[j]) then
        ans = ans .. string.upper(string.sub(s, i, i));
        done = true;
        break;
      end
    end
    if (done == false) then
    ans = ans .. string.sub(s, i, i)
  end;
  end
  return ans;
end

print(capitalize("Hola, mundo!", { 1, 4, 4, 2, 5, 1, 4,8 }))

-- Para estudiar

--[[
function indexcap.capitalize(s,arr)
  local t = {}
  for i = 1, #s do
    t[i] = s:sub(i, i):lower()
  end
  for i = 1, #arr do
    if t[arr[i]+1] then
      t[arr[i]+1] = t[arr[i]+1]:upper()
    end
  end
  return table.concat(t)
end
--]]

--[[
function indexcap.capitalize( s, a )
  for _, n in ipairs( a ) do
    s = s:sub( 1, n ) .. s:sub( n+1, n+1 ):upper() .. s:sub( n+2 )
  end
  return s
end
--]]
