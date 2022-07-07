--[[
Write a function that accepts an integer n and a string s as parameters, and returns a string of s repeated exactly n times.

Examples (input -> output)
6, "I"     -> "IIIIII"
5, "Hello" -> "HelloHelloHelloHelloHello"
--]]

kata = {}

function kata.repeatStr(r, string)
	local answer = ""
	for i = 1, r, 1 do
		answer = answer .. string
	end
	return answer
end

print(kata.repeatStr(6, "Hola"))

-- Para terner en cuenta
-- function repeatStr(r, string)
--   return string:rep(r)
-- end


