/*
Given a number n, draw stairs using the letter "I", n tall and n wide, with the tallest in the top left.

For example n = 3 result in:

"I\n I\n  I"
or printed:

I
 I
  I
Another example, a 7-step stairs should be drawn like this:

I
 I
  I
   I
    I
     I
      I
*/

function drawStairs(n) {
  let ans = "I\n";
  let spaces = " ";
  for (let i = 1; i < n; i++) {
    ans += spaces + "I\n";
    spaces += " ";
  }
  return ans.slice(0,-1);
}

console.log(drawStairs(2))

// El código a continuación resuelve el ejercicio con una
// elegancia y simpleza suprema.
// Es básicametne como hacer las listas en python en una línea
// un recurso que tengo que empezar a usar.

const drawStairs = n => [...Array(n)].map((_, i) => " ".repeat(i) + "I").join("\n");

