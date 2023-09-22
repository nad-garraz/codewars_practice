/*
Write a function that takes two arguments, and returns a new array populated with the elements that only appear once, in either one array or the other, taken only once; display order should follow what appears in arr1 first, then arr2:

hotSingles([1, 2, 3, 3], [3, 2, 1, 4, 5]) // [4, 5]
hotSingles(["tartar", "blanket", "cinnamon"], ["cinnamon", "blanket", "domino"]) // ["tartar", "domino"]
hotSingles([77, "ciao"], [78, 42, "ciao"]) // [77, 78, 42]
hotSingles([1, 2, 3, 3], [3, 2, 1, 4, 5, 4]) // [4,5]
*/


// Solve the challenge
//
// function hotSingles (arr1, arr2) {
//   const diff = (a, b) => a.filter(e => !b.includes(e));
//   return [... new Set([...diff(arr1,arr2), ...diff(arr2,arr1)])]
// }

//Solucion más elegante
const hotSingles = (arr1, arr2) =>
  [...new Set([...arr1, ...arr2])].filter(val => !arr1.includes(val) || !arr2.includes(val));

const a = [1,2]
const b = [1,2]

console.log(hotSingles([1, 2, 3, 3,6,6,6,6], [3, 2, 1]))

console.log(hotSingles([1, 2, 3, 3], [3, 2, 1, 4, 5])) // [4, 5]

console.log(hotSingles(["tartar", "blanket", "cinnamon"], ["cinnamon", "blanket", "domino"])) // ["tartar", "domino"]
