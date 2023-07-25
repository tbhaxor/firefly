#include <algorithm>
#include <iostream>
#include <vector>

#include "firefly/vector.hpp"

int main() {
  std::vector<Real> vec1{6, 8};
  std::vector<Real> vec2{-8, 6};

  Firefly::Vector v1{vec1};
  Firefly::Vector v2{vec2};

  auto v3 = v1 + v2;

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;

  std::cout << v1.Normalize() << "\t" << v1.Normalize().Magnitude() << "\t"
            << std::boolalpha << v1.IsNormalized() << "\t"
            << v1.Normalize().IsNormalized() << std::noboolalpha << std::endl;
}
