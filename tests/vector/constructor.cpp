#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, construct__from_size) {
  Firefly::Vector v{0};

  ASSERT_EQ(v.Size(), 0);
}

TEST(Vector, construct__with_size__zero) {
  Firefly::Vector v{4};

  ASSERT_EQ(v.Size(), 4);
  ASSERT_TRUE(v.IsZero());
}

TEST(Vector, construct__from_std_vector) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_EQ(v.Size(), 4);
  ASSERT_EQ(v.ElemSum(), 10);
}

TEST(Vector, construct__from_firefly_vector) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{v1};

  ASSERT_EQ(v1, v2);
}