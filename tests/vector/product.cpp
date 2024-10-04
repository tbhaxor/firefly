#include <cmath>

#include "firefly/utilities.hpp"
#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(vector, scale__zero_returns_zero_vector) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};
  v1 *= 0;

  ASSERT_EQ(v1[0], 0);
  ASSERT_EQ(v1[1], 0);
  ASSERT_EQ(v1[2], 0);
  ASSERT_EQ(v1[3], 0);
}

TEST(vector, scale__type_cast) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};
  auto v2 = v1 * 1.5;

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<double, 4>>));

  ASSERT_DOUBLE_EQ(v2[0], 1.5);
  ASSERT_DOUBLE_EQ(v2[1], 3);
  ASSERT_DOUBLE_EQ(v2[2], 4.5);
  ASSERT_DOUBLE_EQ(v2[3], 6);
}

TEST(vector, scale__no_type_cast_when_inplace) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};
  v1 *= 1.5;

  ASSERT_TRUE((std::is_same_v<decltype(v1), firefly::vector<int, 4>>));

  ASSERT_EQ(v1[0], 1);
  ASSERT_EQ(v1[1], 3);
  ASSERT_EQ(v1[2], 4);
  ASSERT_EQ(v1[3], 6);
}

TEST(vector, scale__with_negative_numbers) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};
  auto v2 = v1 * -1.5;

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<double, 4>>));

  ASSERT_DOUBLE_EQ(v2[0], -1.5);
  ASSERT_DOUBLE_EQ(v2[1], -3);
  ASSERT_DOUBLE_EQ(v2[2], -4.5);
  ASSERT_DOUBLE_EQ(v2[3], -6);
}

TEST(vector, scale__with_neg_1_makes_it_anti_parallel) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};
  auto v2 = v1 * -1;

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<int, 4>>));

  ASSERT_EQ(v2[0], -1);
  ASSERT_EQ(v2[1], -2);
  ASSERT_EQ(v2[2], -3);
  ASSERT_EQ(v2[3], -4);
}

TEST(vector, scale__complex_type) {
  firefly::vector<std::complex<int>, 4> v1{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  auto v2 = v1 * -1.5;

  ASSERT_TRUE((std::is_same_v<decltype(v2), firefly::vector<std::complex<double>, 4>>));

  ASSERT_DOUBLE_EQ(std::real(v2[0]), -1.5);
  ASSERT_DOUBLE_EQ(std::imag(v2[0]), -3);
  ASSERT_DOUBLE_EQ(std::real(v2[1]), -4.5);
  ASSERT_DOUBLE_EQ(std::imag(v2[1]), -6);
  ASSERT_DOUBLE_EQ(std::real(v2[2]), -7.5);
  ASSERT_DOUBLE_EQ(std::imag(v2[2]), -9);
  ASSERT_DOUBLE_EQ(std::real(v2[3]), -10.5);
  ASSERT_DOUBLE_EQ(std::imag(v2[3]), -12);
}

TEST(vector, scale__works_with_unary_operator) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};

  ASSERT_TRUE(firefly::utilities::vector::are_anti_parallel(v1, -v1));
}

TEST(vector, scale__reciprocal_works) {
  firefly::vector<int, 4> v1{1, 2, 3, 4};
  auto v2 = v1 / v1.norm();

  ASSERT_DOUBLE_EQ(v2.norm(), 1);
}

TEST(vector, scale__reciprocal_works_inplace) {
  firefly::vector<double, 4> v1{1, 2, 3, 4};
  v1 /= v1.norm();
  ASSERT_DOUBLE_EQ(v1.norm(), 1);
}

TEST(vector, cross__zero_returns_zero) {
  firefly::vector<int, 3> v1;
  firefly::vector<int, 3> v2;
  auto v3 = v1.cross(v2);

  ASSERT_TRUE((std::is_same_v<decltype(v3), firefly::vector<int, 3>>));

  ASSERT_EQ(v3[0], 0);
  ASSERT_EQ(v3[1], 0);
  ASSERT_EQ(v3[2], 0);
}

TEST(vector, cross__zero_non_zero_returns_zero) {
  firefly::vector<int, 3> v1;
  firefly::vector<int, 3> v2{1, 2, 3};
  auto v3 = v1.cross(v2);

  ASSERT_TRUE((std::is_same_v<decltype(v3), firefly::vector<int, 3>>));
  ASSERT_EQ(v3[0], 0);
  ASSERT_EQ(v3[1], 0);
  ASSERT_EQ(v3[2], 0);
}

TEST(vector, cross__orthogonal_returns_product_of_magnitude_of_vectors) {
  firefly::vector<int, 3> v1{1, 0, 0};
  firefly::vector<int, 3> v2{0, 1, 1};
  auto v3 = v1.cross(v2);

  ASSERT_EQ(v3.norm(), v1.norm() * v2.norm());
  ASSERT_EQ(v3[0], 0);
  ASSERT_EQ(v3[1], -1);
  ASSERT_EQ(v3[2], 1);
}

TEST(vector, cross__parallel_vectors_returns_zero) {
  firefly::vector<int, 3> v1{1, 0, 0};
  v1 = v1.cross(v1);

  ASSERT_EQ(v1[0], 0);
  ASSERT_EQ(v1[1], 0);
  ASSERT_EQ(v1[2], 0);
}

TEST(vector, cross__regular_with_different_types) {
  firefly::vector<int, 3> v1{1, 0, 0};
  firefly::vector<double, 3> v2{1, std::sqrt(3), 0};
  auto v3 = v1.cross(v2);

  ASSERT_TRUE((std::is_same_v<decltype(v3), firefly::vector<double, 3>>));

  ASSERT_DOUBLE_EQ(v3[0], 0);
  ASSERT_DOUBLE_EQ(v3[1], 0);
  ASSERT_NEAR(v3[2], 1.7320508075688772, 1.73205);
}

TEST(vector, dot__regular_returns_scalar) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<int, 3> v2{4, 5, 6};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), int>));

  ASSERT_EQ(v1 * v2, 32);
}

TEST(vector, dot__different_type_auto_cast) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<double, 3> v2{4, 5, 6};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), double>));

  ASSERT_DOUBLE_EQ(v1 * v2, 32);
}

TEST(vector, dot__complex_scalar_returns_complex) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<std::complex<int>, 3> v2{{1, 2}, {3, 4}, {5, 6}};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), std::complex<int>>));

  ASSERT_EQ(std::real(v1 * v2), 22);
  ASSERT_EQ(std::imag(v1 * v2), 28);
}

TEST(vector, dot__complex_scalar_different_type_auto_cast_returns_complex) {
  firefly::vector<double, 3> v1{1, 2, 3};
  firefly::vector<std::complex<int>, 3> v2{{1, 2}, {3, 4}, {5, 6}};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), std::complex<double>>));

  ASSERT_DOUBLE_EQ(std::real(v1 * v2), 22);
  ASSERT_DOUBLE_EQ(std::imag(v1 * v2), 28);
}

TEST(vector, dot__complex_complex_same_type_return_same_complex) {
  firefly::vector<std::complex<int>, 3> v1{{1, 2}, {3, 4}, {5, 6}};
  firefly::vector<std::complex<int>, 3> v2{{1, 2}, {3, 4}, {5, 6}};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), std::complex<int>>));

  ASSERT_EQ(std::real(v1 * v2), -21);
  ASSERT_EQ(std::imag(v1 * v2), 88);
}

TEST(vector, dot__complex_complex_different_types_return_auto_complex) {
  firefly::vector<std::complex<int>, 3> v1{{1, 2}, {3, 4}, {5, 6}};
  firefly::vector<std::complex<double>, 3> v2{{1, 2}, {3, 4}, {5, 6}};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), std::complex<double>>));

  ASSERT_DOUBLE_EQ(std::real(v1 * v2), -21);
  ASSERT_DOUBLE_EQ(std::imag(v1 * v2), 88);
}

TEST(vector, dot__orthogonal_returns_zero) {
  firefly::vector<int, 3> v1{1, 2, 1};
  firefly::vector<int, 3> v2{1, 2, -5};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), int>));

  ASSERT_EQ(v1 * v2, 0);
}

TEST(vector, dot__orthogonal_same_return_magnitude_powered) {
  firefly::vector<int, 3> v1{1, 2, 1};

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v1), int>));

  ASSERT_DOUBLE_EQ(v1 * v1, std::pow(v1.norm(), 2));
}

TEST(vector, dot__parallel_vectors_return_magnitude_multiplied) {
  firefly::vector<int, 3> v1{1, 2, 1};
  auto v2 = v1 * 2;

  ASSERT_TRUE((std::is_same_v<decltype(v1 * v2), int>));

  ASSERT_DOUBLE_EQ(v1 * v2, v1.norm() * v2.norm());
  ASSERT_DOUBLE_EQ(v1 * v2, std::pow(v1.norm(), 2) * 2);
}