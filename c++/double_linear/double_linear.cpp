/*
Consider a sequence u where u is defined as follows:

1 - The number u(0) = 1 is the first one in u.
2 - For each x in u, then y = 2 * x + 1 and z = 3 * x + 1 must be in u too.
3 - There are no other numbers in u.
Ex: u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]

1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13, then 7 gives 15 and 22
and so on...

Task:
Given parameter n the function dbl_linear (or dblLinear...) returns the element
u(n) of the ordered (with <) sequence u (so, there are no duplicates).

Example:
dbl_linear(10) should return 22
dbl_linear(100) should return 447
dbl_linear(6000) should return 80914
dbl_linear(100000) should return 2911593

Note:
Focus attention on efficiency
*/

#include <iostream>
#include <queue>
#include <vector>

class DoubleLinear
{
public:
  static int dblLinear(int n)
  {
    int              x{1};
    int              y, z = 0;
    int              element{};
    std::vector<int> sol = {1};
    std::queue<int>  z_queue;

    while (sol.size() <= n) // Si n = 1 el
    {
      y = 2 * x + 1;
      /*std::cout << "y: " << y << std::endl;*/
      /*std::cout << "x: " << x << std::endl;*/
      int z = y + x;
      if (true)
      {
        int z = y + x;
        z_queue.push(z);
      }

      while (y > z_queue.front() && z_queue.size() > 0)
      {
        if (z_queue.front() == sol.back())
        {
          z_queue.pop();
        }
        else
        {
          /*std::cout << "zpush: " << z;*/
          sol.push_back(z_queue.front());
          if (sol.size() > n)
          {

            /*std::cout << "sol: ";*/
            /*for (int elem : sol)*/
            /*{*/
            /*  std::cout << elem << ",";*/
            /*}*/
            /**/
            /*std::cout << "return" << std::endl;*/
            return sol.back();
          }
        }
      }

      sol.push_back(y);
      x = sol[++element];

      /*std::cout << "element: " << element << "\n" << "sol: ";*/
      /**/
      /*for (int elem : sol)*/
      /*{*/
      /*  std::cout << elem << ",";*/
      /*}*/
      /**/
      /*std::cout << std::endl;*/
      /*std::cout << "Next x: " << x << "\n\n\n\n";*/
    }
    return sol.back();
  };
};

int main(int argc, char *argv[])
{
  DoubleLinear Dl;
  std::cout << "n = 1 -> " << Dl.dblLinear(1) <<"  Fin" << std::endl;
  std::cout << "n = 2 -> " << Dl.dblLinear(2) << "  Fin" << std::endl;
  std::cout << "n = 3 -> " << Dl.dblLinear(3) << "  Fin" << std::endl;
  std::cout << "n = 4 -> " << Dl.dblLinear(4) << std::endl;
  std::cout << "n = 5 -> " << Dl.dblLinear(5) << std::endl;
  std::cout << "n = 10 -> " << Dl.dblLinear(10) << std::endl;
  std::cout << "n = 20 -> " << Dl.dblLinear(20) << std::endl;
  std::cout << "n = 30 -> " << Dl.dblLinear(30) << std::endl;
  std::cout << "n = 50 -> " << Dl.dblLinear(50) << std::endl;
  return 0;
}
