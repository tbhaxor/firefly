#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, dot__different_size__error) {
  Firefly::Vector v1{10};
  Firefly::Vector v2{5};

  ASSERT_THROW({ auto _ = v1.Dot(v2); }, std::length_error);
}

TEST(Vector, dot__zero__zero) {
  Firefly::Vector v1{5};
  Firefly::Vector v2{5};

  ASSERT_EQ(v1.Dot(v2), 0);
}

TEST(Vector, dot__zero_non_zero__zero) {
  Firefly::Vector v1{{1, 2, 3, 4, 5}};
  Firefly::Vector v2{5};

  ASSERT_EQ(v1.Dot(v2), 0);
}

TEST(Vector, dot__orthogonal__zero) {
  Firefly::Vector v1{{5, -4}};
  Firefly::Vector v2{{4, 5}};

  ASSERT_EQ(v1.Dot(v2), 0);
}

TEST(Vector, dot__same__mag_sqed) {
  Firefly::Vector v1{{3, -4}};

  ASSERT_EQ(v1.Dot(v1), std::pow(v1.Magnitude(), 2));
}

TEST(Vector, dot__parallel__maq_multiplied) {
  Firefly::Vector v1{{3, -4}};
  auto v2 = v1 * 4;

  ASSERT_EQ(v1.Dot(v2), v1.Magnitude() * v2.Magnitude());
}

TEST(Vector, dot__regular__non_zero) {
  Firefly::Vector v1{{3, -4}};
  Firefly::Vector v2{{4, 5}};

  ASSERT_EQ(v1.Dot(v2), -8);
}