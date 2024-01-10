/*
DESCRIPTION:
Write a function that accepts a square matrix (N x N 2D array) and returns the
determinant of the matrix.

How to take the determinant of a matrix -- it is simplest to start with the
smallest cases:

A 1x1 matrix |a| has determinant a.

A 2x2 matrix [ [a, b], [c, d] ] or

|a  b|
|c  d|
has determinant: a*d - b*c.

The determinant of an n x n sized matrix is calculated by reducing the problem
to the calculation of the determinants of n matrices ofn-1 x n-1 size.

For the 3x3 case, [ [a, b, c], [d, e, f], [g, h, i] ] or

|a b c|
|d e f|
|g h i|
the determinant is: a * det(a_minor) - b * det(b_minor) + c * det(c_minor) where
det(a_minor) refers to taking the determinant of the 2x2 matrix created by
crossing out the row and column in which the element a occurs:

|- - -|
|- e f|
|- h i|
Note the alternation of signs.

The determinant of larger matrices are calculated analogously, e.g. if M is a
4x4 matrix with first row [a, b, c, d], then:

det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d *
det(d_minor)
*/

#include <iostream>
#include <vector>

using namespace std;

long long                 det2x2(vector<vector<long long>> matrix);
vector<vector<long long>> get_minor(vector<vector<long long>> matrix, int col);
long long                 determinant(vector<vector<long long>> matrix);

int main()
{
  // vector<vector<long long>> matrix = {{1, 2, 3}, {2, 1, 1}, {1, 1, 1}};
  // vector<vector<long long>> matrix = {{2, 3, 4}, {5, 6, 7}, {9, 9, 9}};
  // vector<vector<long long>> matrix = {{12, 2, 1}, {3, 44, 23}, {3, 3, 2}};
  // vector<vector<long long>> matrix = {{1, 0, 2, 0}, {2, 2, 3, 2}, {3, 3, 2,
  // 0}, {0, 2, 2, 3}};
  vector<vector<long long>> matrix = {{1, 0, 2, 0, 4}, {2, 2, 3, 2, 1}, {3, 3, 2, 0, 3}, {0, 2, 2, 3, 4}, {0, 2, -1, 3, 4}};
  // vector<vector<long long>> matrix = {{2}};
  cout << "Determinante: " << determinant(matrix) << endl;
  return 0;
}

// return determinant of 2x2 matrix
long long det2x2(vector<vector<long long>> matrix) { return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]; }

// returns matrix with out first row and #col column.
vector<vector<long long>> get_minor(vector<vector<long long>> matrix, int col)
{
  int                       dim = matrix.size();
  vector<vector<long long>> minor;
  for (int row{1}; row < dim; ++row)
  {
    vector<long long> r;
    for (int column{}; column < dim; ++column)
    {
      if (column != col)
      {
        r.push_back(matrix[row][column]);
      }
    }
    minor.push_back(r);
  }
  // cout << "print minor" << endl;
  // for (int r{}; r < dim - 1; r++)
  // {
  //   for (int c{}; c < dim - 1; c++)
  //   {
  //     cout << minor[r][c] << " ";
  //   }
  //   cout << endl;
  // }
  return minor;
}

long long determinant(vector<vector<long long>> matrix)
{
  int dim = matrix.size();

  if (dim == 1)
  {
    return matrix[0][0];
  }
  else if (dim == 2)
  {
    return det2x2(matrix);
  }

  long long det{};
  for (int column{0}; column < dim; column++)
  {
    if (column % 2)
    {
      det -= matrix[0][column] * determinant(get_minor(matrix, column));
    }
    else
    {
      det += matrix[0][column] * determinant(get_minor(matrix, column));
    }
  }
  return det;
}
