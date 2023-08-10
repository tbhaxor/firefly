#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, elemsum__empty__zero) {
  Firefly::Vector v{0};

  ASSERT_EQ(v.ElemSum(), 0);
}

TEST(Vector, elemsum__zero__zero) {
  Firefly::Vector v{10};

  ASSERT_EQ(v.ElemSum(), 0);
}

TEST(Vector, elemsum__non_zero__non_zero) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_EQ(v.ElemSum(), 10);
}
