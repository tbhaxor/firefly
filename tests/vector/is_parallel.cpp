#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, is_parallel__unequal_size__false) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{1, 2, 3}};

  ASSERT_FALSE(v1.IsParallel(v2));
}

TEST(Vector, is_parallel__zero__true) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsParallel(v * 0)); });
}

TEST(Vector, is_parallel__same__true) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsParallel(v)); });
}

TEST(Vector, is_parallel__opposite__true) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsParallel(-v)); });
}

TEST(Vector, is_parallel__otherwise__false) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{2, 2, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_FALSE(v1.IsParallel(-v2)); });
}