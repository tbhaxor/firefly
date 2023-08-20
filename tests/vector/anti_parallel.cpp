#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, subtract__unary__make_opposite) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_NO_THROW({
    ASSERT_TRUE(v.IsParallel(-v));
    ASSERT_NEAR(v.AngleWith(-v), M_PI, Firefly_TEST_EPSILON);
  });
}
