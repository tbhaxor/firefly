#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, is_same__unequal_size__false) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{1, 2, 3}};

  ASSERT_FALSE(v1 == v2);
}

TEST(Vector, is_same__all_equal__true) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_TRUE(v == v);
}

TEST(Vector, is_same__any_one_diff__false) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{1, 2, 3, 5}};

  ASSERT_FALSE(v1 == v2);
}
