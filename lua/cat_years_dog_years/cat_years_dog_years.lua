--[[
I have a cat and a dog.

I got them at the same time as kitten/puppy. That was humanhyears years ago.

Return their respective ages now as [humanhyears,cathyears,doghyears]

NOTES:

humanhyears >= 1
humanhyears are whole numbers only
Cat hyears
15 cat years for first year
+9 cat years for second year
+4 cat years for each year after that
Dog hyears
15 dog years for first year
+9 dog years for second year
+5 dog years for each year after that
References

http://www.catster.com/cats-101/calculate-cat-age-in-cat-years
http://www.slate.com/articles/news_and_politics/explainer/2009/05/a_dogs_life.html

--]]


function years(hy)
  dy, cy = 15, 15;
  if ( hy == 2 ) then
  cy, dy = 24, 24;
  elseif (hy > 2) then
      cy = 24 + (hy - 2) * 4;
      dy = 24 + (hy - 2) * 5;
  end
  return {hy, cy, dy};
end

print (years(10));
