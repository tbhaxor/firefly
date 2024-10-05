#include <cmath>

#include "firefly/utilities.hpp"
#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(vector, misc__norm_arithmetic_returns_arithmetic) {
  firefly::vector<int, 2> v1{3, 4};
  firefly::vector<int, 2> v2{-3, -4};
  firefly::vector<double, 2> v3{6, 8};

  ASSERT_TRUE((std::is_same_v<decltype(v1.norm()), double>));
  ASSERT_TRUE((std::is_same_v<decltype(v2.norm()), double>));
  ASSERT_TRUE((std::is_same_v<decltype(v3.norm()), double>));

  ASSERT_DOUBLE_EQ(v1.norm(), 5);
  ASSERT_DOUBLE_EQ(v2.norm(), 5);
  ASSERT_DOUBLE_EQ(v3.norm(), 10);
}

TEST(vector, misc__norm_complex_returns_arithmetic) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};

  ASSERT_TRUE((std::is_same_v<decltype(v1.norm()), double>));

  ASSERT_DOUBLE_EQ(v1.norm(), 5.4772255750516612);
}

TEST(vector, misc__to_normalized_works_with_arithmetic) {
  firefly::vector<int, 2> v1{3, 4};
  auto v2 = v1.to_normalized();

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<double, 2>>));

  ASSERT_DOUBLE_EQ(v2[0], v1[0] / v1.norm());
  ASSERT_DOUBLE_EQ(v2[1], v1[1] / v1.norm());
}

TEST(vector, misc__to_normalized_norm_is_1) {
  firefly::vector<int, 2> v1{3, 4};
  auto v2 = v1.to_normalized();

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<double, 2>>));

  ASSERT_DOUBLE_EQ(v2.norm(), 1);
}

TEST(vector, misc__to_normalized_complex_returns_complex_vector) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};
  auto v2 = v1.to_normalized();

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<std::complex<double>, 2>>));

  ASSERT_DOUBLE_EQ(std::real(v2[0]), std::real(v1[0]) / v1.norm());
  ASSERT_DOUBLE_EQ(std::imag(v2[0]), std::imag(v1[0]) / v1.norm());
  ASSERT_DOUBLE_EQ(std::real(v2[1]), std::real(v1[1]) / v1.norm());
  ASSERT_DOUBLE_EQ(std::imag(v2[1]), std::imag(v1[1]) / v1.norm());
}

TEST(vector, misc__to_normalized_complex_norm_returns_1) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};
  auto v2 = v1.to_normalized();

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<std::complex<double>, 2>>));

  ASSERT_DOUBLE_EQ(v2.norm(), 1);
}

TEST(vector, misc__equals_works_with_arithmetic) {
  firefly::vector<int, 2> v1{1, 2};

  ASSERT_TRUE((std::is_same_v<decltype(v1 == v1), bool>));

  ASSERT_TRUE(v1 == v1);
  ASSERT_FALSE(v1 == -v1);
}

TEST(vector, misc__equals_works_with_complex) {
  firefly::vector<std::complex<int>, 2> v1{{1, 2}, {3, 4}};

  ASSERT_TRUE((std::is_same_v<decltype(v1 == v1), bool>));

  ASSERT_TRUE(v1 == v1);
  ASSERT_FALSE(v1 == -v1);
}

// TODO: Add test for as_type

TEST(vector, misc__view_returns_bracket_enclosed) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 0> v2;

  ASSERT_STREQ(v1.view().c_str(), "[1, 2]");
  ASSERT_STREQ(v2.view().c_str(), "[]");
}

TEST(firefly, misc__common_type_returns_appropriate_types) {
  ASSERT_TRUE((std::is_same_v<firefly::common_type_t<double, std::complex<int>>, std::complex<double>>));
  ASSERT_TRUE((std::is_same_v<firefly::common_type_t<int, std::complex<float>>, std::complex<float>>));
  ASSERT_TRUE((std::is_same_v<firefly::common_type_t<std::complex<double>, int>, std::complex<double>>));
  ASSERT_TRUE(
      (std::is_same_v<firefly::common_type_t<std::complex<float>, std::complex<double>>, std::complex<double>>));
  ASSERT_TRUE((std::is_same_v<firefly::common_type_t<int, double>, double>));
}