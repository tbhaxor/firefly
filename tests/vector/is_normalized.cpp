#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, is_normalized__empty__false) {
  Firefly::Vector v{0};

  ASSERT_FALSE(v.IsNormalized());
}

TEST(Vector, is_normalized__zero__false) {
  Firefly::Vector v{10};

  ASSERT_FALSE(v.IsNormalized());
}

TEST(Vector, is_normalized__normalize_check__true) {
  Firefly::Vector v{{56, 33}};

  ASSERT_TRUE(v.Normalize().IsNormalized());
}

TEST(Vector, is_normalized__normalized__true) {
  Firefly::Vector v{{0.6, 0.8}};

  ASSERT_TRUE(v.IsNormalized());
}

TEST(Vector, is_normalized__basis__true) {
  Firefly::Vector v1{{1, 0, 0}};
  Firefly::Vector v2{{0, 1, 0}};
  Firefly::Vector v3{{0, 0, 1}};

  ASSERT_TRUE(v1.IsNormalized());
  ASSERT_TRUE(v2.IsNormalized());
  ASSERT_TRUE(v3.IsNormalized());
}
