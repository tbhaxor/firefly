#include <firefly/utilities.hpp>
#include <firefly/vector.hpp>
#include <iostream>

int main() {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 6};
  auto v3 = v1 + v2;
  firefly::vector<std::complex<int>, 5> v4{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
  auto v5 = v4.as_type<int>();

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
  std::cout << v3 << std::endl;
  std::cout << v4 << std::endl;
  std::cout << v5 << std::endl;
  std::cout << 1 + v1 << std::endl;
  std::cout << 1.2f + v1 << std::endl;
  std::cout << std::complex<int>{1, 2} + v1 << std::endl;
  std::cout << std::complex<float>{1.3, 2.5} + v1 << std::endl;
  std::cout << v1.norm() << std::endl;
  std::cout << v1.to_normalized().norm() << std::endl;
  std::cout << firefly::utilities::vector::angle_between(v1, v2) << std::endl
            << std::boolalpha << firefly::utilities::vector::are_orthogonal(v1, firefly::vector<int, 2>{-2, 1})
            << std::endl
            << firefly::utilities::vector::are_parallel(v1, v1) << std::endl
            << firefly::utilities::vector::are_anti_parallel(v1, -v1) << std::endl
            << std::noboolalpha;

  firefly::vector<double, 2> x{1, 2};
  firefly::vector<double, 2> y{3, 4};
  std::cout << firefly::utilities::vector::projection(v1, v2) << std::endl;
}
