#include <algorithm>
#include <iostream>
#include <vector>

#include "firefly/vector.hpp"

int main() {
  std::vector<Real> vec1{3, 3};
  std::vector<Real> vec2{2, -2};
  Firefly::Vector v1{vec1};
  Firefly::Vector v2{vec2};

  auto v3 = v2 * 4;

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << *v3 << std::endl;
}
