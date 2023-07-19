/*
An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

isIsogram "Dermatoglyphics" = true
isIsogram "moose" = false
isIsogram "aba" = false
*/

const isIsogram = (str) => {
  str = str.toLowerCase();
  for (let a = 0; a < str.length; a++)
    if (str.slice(a + 1).includes(str[a])) return false;

  return true;
};

var str1 = "abca";
var str2 = "abBd";
var str3 = "abcdeff";
var str4 = "abcdef";

console.log(isIsogram(str1));
console.log(isIsogram(str2));
console.log(isIsogram(str3));
console.log(isIsogram(str4));
