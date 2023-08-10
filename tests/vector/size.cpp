#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, size__empty__zero) {
  Firefly::Vector v{0};

  ASSERT_EQ(v.Size(), 0);
}

TEST(Vector, size__non_empty__non_zero) {
  Firefly::Vector v{10};

  ASSERT_EQ(v.Size(), 10);
}
