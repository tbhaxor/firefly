#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, magnitude__empty__zero) {
  Firefly::Vector v{0};

  ASSERT_EQ(v.Magnitude(), 0);
}

TEST(Vector, magnitude__zero__zero) {
  Firefly::Vector v{10};

  ASSERT_EQ(v.Magnitude(), 0);
}

TEST(Vector, magnitude__non_zero__non_zero) {
  Firefly::Vector v{{3, 4}};

  ASSERT_EQ(v.Magnitude(), 5);
}

TEST(Vector, magnitude__normalized__1) {
  Firefly::Vector v{{0.6, 0.8}};

  ASSERT_EQ(v.Magnitude(), 1);
}
