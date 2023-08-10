#include "firefly/vector.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Vector, angle_with__zero_vector__error) {
  Firefly::Vector v{10};

  ASSERT_THROW({ auto _ = v.AngleWith(v); }, std::logic_error);
}

TEST(Vector, angle_with__perp_vector__90) {
  Firefly::Vector v1{{3, 4}};
  Firefly::Vector v2{{-4, 3}};

  ASSERT_NO_THROW({ ASSERT_EQ(v1.AngleWith(v2), M_PI / 2); });
}

TEST(Vector, angle_with__parallel_vector__180) {
  Firefly::Vector v{{1, 3}};

  ASSERT_NO_THROW({
    EXPECT_NEAR(v.AngleWith(v), 0,
                std::max(static_cast<Real>(0), v.AngleWith(v)));
  });
}

TEST(Vector, angle_with__opp_vector__180) {
  using namespace ::testing;
  Firefly::Vector v{{3, -1}};

  ASSERT_NO_THROW({ ASSERT_NEAR(v.AngleWith(-v), M_PI, 0.01); });
}

TEST(Vector, angle_with__regular_vector) {
  using namespace ::testing;
  Firefly::Vector v1{{3, 7}};
  Firefly::Vector v2{{2, 0}};

  ASSERT_NO_THROW(
      { ASSERT_THAT(v1.AngleWith(v2), AnyOf(Ge(-M_PI), Le(M_PI))); });
}
