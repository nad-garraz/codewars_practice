#include <iostream>
#include <vector>

int sum(std::vector<int> v);

int main() {
  std::vector<int> v = {1, 1, 1};
  std::vector<int> s;
  v[1] = 4;
  s.assign(3, 200);
  size_t size = v.size();
  for (int item : v) {
    printf("%d\n", item);
  }
  for (int item : s) {
    printf("%d\n", item);
  }
  printf("size: %zu\n", size);

  // Funcion sum

  std::vector<int> t = {40, 2, 10, 4, 21, 2000, 23};
  int suma = sum(t);
  printf("Suma de los elementos sin los máximos: %d\n", suma);
  return 0;
}

// Sumar los elementos de un vector sin incluir los dos valores más altos sin
// contar repeticiones, ie< 1, 1, 2, 3, 4, 5 > ==> sum = 10
//< 3, 2, 5, 3, 4, 5 > ==> sum = 15
//

int sum(std::vector<int> v) {
  if (v.size() < 2)
    return 9999;
  int total = {0};
  int high = v[0];
  int low = v[0];
  int n = {0};
  for (int item : v) {
    if (item < low) {
      low = item;
    } else if (item > high) {
      high = item;
    }
    total += item;
  }
  return total - high - low;
}
