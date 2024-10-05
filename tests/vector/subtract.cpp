#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(vector, subtract__different_types_return_common_type_and_performs_element_wise) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<float, 3> v2{1, 2, 3};

  auto v3 = v1 - v2;
  ASSERT_TRUE((std::is_same_v<decltype(v3), firefly::vector<float, 3>>));

  ASSERT_EQ(v1[0] - v2[0], v3[0]);
  ASSERT_EQ(v1[1] - v2[1], v3[1]);
  ASSERT_EQ(v1[2] - v2[2], v3[2]);
}

TEST(vector, subtract__scalar_broadcasting) {
  firefly::vector<int, 3> v1{1, 2, 3};
  auto v2 = v1 - 10;

  ASSERT_EQ(v1[0] - 10, v2[0]);
  ASSERT_EQ(v1[1] - 10, v2[1]);
  ASSERT_EQ(v1[2] - 10, v2[2]);
}

TEST(vector, subtract__assign_updates_current_vector) {
  firefly::vector<int, 3> v1{1, 2, 3};
  auto v2 = v1 -= 10;

  ASSERT_EQ(v1[0], -9);
  ASSERT_EQ(v1[1], -8);
  ASSERT_EQ(v1[2], -7);
}

TEST(vector, subtract__works_with_functions) {
  firefly::vector<int, 3> v1{1, 2, 3};
  v1 = v1.subtract(10);

  ASSERT_EQ(v1[0], -9);
  ASSERT_EQ(v1[1], -8);
  ASSERT_EQ(v1[2], -7);

  v1 = v1.subtract(v1);

  ASSERT_EQ(v1[0], 0);
  ASSERT_EQ(v1[1], 0);
  ASSERT_EQ(v1[2], 0);

  auto v2 = v1.subtract(1.2);

  ASSERT_FLOAT_EQ(v2[0], -1.2);
  ASSERT_FLOAT_EQ(v2[1], -1.2);
  ASSERT_FLOAT_EQ(v2[2], -1.2);
}

TEST(vector, subtract__complex_complex_returns_complex) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};
  firefly::vector<std::complex<int>, 2> v2{{5, 6}, {7, 8}};
  auto v3 = v1 - v2;
  ASSERT_TRUE((std::is_same_v<decltype(v3), firefly::vector<std::complex<int>, 2>>));
}

TEST(vector, subtract__complex_complex_different_type_returns_bigger_type) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};
  firefly::vector<std::complex<double>, 2> v2{{1, 2}, {3, 4}};
  auto v3 = v1 - v2;

  ASSERT_TRUE((std::is_same_v<decltype(v3), firefly::vector<std::complex<double>, 2>>));
}

TEST(vector, subtract__complex_scalar_returns_complex) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};
  auto v2 = v1 - 1.1f;

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<std::complex<float>, 2>>));

  ASSERT_FLOAT_EQ(std::real(v2[0]), -0.1);
  ASSERT_FLOAT_EQ(std::imag(v2[0]), 2);
  ASSERT_FLOAT_EQ(std::real(v2[1]), 1.9);
  ASSERT_FLOAT_EQ(std::imag(v2[1]), 4);
}

TEST(vector, subtract__complex_to_scalar_return_complex_of_common_type) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};
  auto v2 = v1 - 1.1f;

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<std::complex<float>, 2>>));

  ASSERT_FLOAT_EQ(std::real(v2[0]), -0.1);
  ASSERT_FLOAT_EQ(std::imag(v2[0]), 2);
  ASSERT_FLOAT_EQ(std::real(v2[1]), 1.9);
  ASSERT_FLOAT_EQ(std::imag(v2[1]), 4);
}