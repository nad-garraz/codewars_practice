--[[
Complete the function/method so that it returns the url with anything after the anchor (#) removed.

Examples
"www.codewars.com#about" --> "www.codewars.com"
"www.codewars.com?page=1" -->"www.codewars.com?page=1"
--]]

-- La que me salió a mí
local removeUrlAnchor = function(s)
	if string.find(s, "#") == nil then
		return s
	end
	return string.sub(s, 1, string.find(s, "#") - 1)
end

print(removeUrlAnchor("www.codewars.com#about"))

-- Para apreder:
--[[
return {
  removeUrlAnchor = function(s)
    return string.gsub(s, '#.*', '')
  end
}
 --]]
