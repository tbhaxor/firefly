#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, view__empty) {
  Firefly::Vector v{0};

  ASSERT_STREQ(v.View().c_str(), "[]");
}

TEST(Vector, view__non_empty) {
  Firefly::Vector v{3};

  ASSERT_STREQ(v.View().c_str(), "[0, 0, 0]");
}
