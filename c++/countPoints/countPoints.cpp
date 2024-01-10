/*
Vonhyou's math teacher give him n functions like this:



where ki and bi are all doubleegers.

After that, the teacher define a function called F(x):



The teacher let Vonhyou count the number of ** vertexs ** in the graph of the
function F(x).

You should write a function countPodoubles.

Input
An array of tuple of two doubleeger [(k1,b1),(k2,b2)...(kn,bn)]

Look sample test cases for more details.

Output
An doubleeger, the answer.
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

double              puntosImportantes(std::pair<double, double> &par);


int main()
{
  std::vector<std::pair<double, double>> vec;
  std::vector<double>                    raices;

  // seed random generator
  std::srand(time(NULL));

  for (size_t t{}; t < 3; t++)
  {
    vec.push_back(std::pair<double, double>(-10 + rand() % 20, -10 + rand() % 20));
  }
  for (auto par : vec)
  {
    // std::cout << par.first << " , " << par.second << std::endl;
    // std::cout << puntosImportantes(par) << std::endl;
    raices.push_back(puntosImportantes(par));
  }

  std::sort(raices.begin(), raices.end());

  for (auto item : raices)
  {
    std::cout << item << std::endl;
  }

  std::vector<double> x(300);
  for (float t{-100}; t < 100; t++)
  {
    x.push_back(t);
  }

  return raices.size();
}



double puntosImportantes(std::pair<double, double> &par)
{
  double m = par.first;
  double b = par.second;
  return m != 0 ? -1 * b / m : 0;
}
