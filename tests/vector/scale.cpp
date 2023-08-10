#include <cmath>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, scale__zero__zero_vector) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_TRUE((v * 0).IsZero());
}

TEST(Vector, scale__any_with_zero_vector__zero_vector) {
  Firefly::Vector v{10};

  ASSERT_TRUE((v * 10).IsZero());
}

TEST(Vector, scale__positive) {
  Firefly::Vector v1{{1, 2, 3}};
  Firefly::Vector v2{{10, 20, 30}};
  Firefly::Vector v3 = v1 * 10;

  ASSERT_EQ(v3, v2);
  ASSERT_EQ(v3.AngleWith(v1), 0);
  ASSERT_TRUE(v3.IsParallel(v1));
}

TEST(Vector, scale__positive_n__n_times_magnitude) {
  Firefly::Vector v{{1, 2, 3}};

  ASSERT_EQ((v * 10).Magnitude(), v.Magnitude() * 10);
}

TEST(Vector, scale__negative__opposite) {
  Firefly::Vector v1{{1, 2, 3}};
  Firefly::Vector v2 = v1 * -1;

  ASSERT_EQ(v2, -v1);
  ASSERT_EQ(v1.AngleWith(v2), M_PI);
  ASSERT_TRUE(v1.IsParallel(v2));
}