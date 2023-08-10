#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, is_zero__empty__true) {
  Firefly::Vector v{0};

  ASSERT_TRUE(v.IsZero());
}

TEST(Vector, is_zero__zero__true) {
  Firefly::Vector v{10};

  ASSERT_TRUE(v.IsZero());
}

TEST(Vector, is_zero__any_non_zero__false) {
  Firefly::Vector v{{1, 0, 0}};

  ASSERT_FALSE(v.IsZero());
}
