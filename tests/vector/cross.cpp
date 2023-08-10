#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(Vector, cross__non_3d__error) {
  Firefly::Vector v{2};

  ASSERT_THROW({ auto _ = v.Cross(v); }, std::length_error);
}

TEST(Vector, cross__zero__zero) {
  Firefly::Vector v{3};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.Cross(v).IsZero()); });
}

TEST(Vector, cross__zero_non_zero__zero) {
  Firefly::Vector v1{3};
  Firefly::Vector v2{{1, 2, 3}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v1.Cross(v2).IsZero()); });
}

TEST(Vector, cross__orthogonal__mag_product) {
  Firefly::Vector v1{{1, 0, 0}};
  Firefly::Vector v2{{0, 1, 1}};

  ASSERT_NO_THROW({
    auto crossed = v1.Cross(v2);

    ASSERT_TRUE(crossed.IsOrthogonal(v1));
    ASSERT_TRUE(crossed.IsOrthogonal(v2));
    ASSERT_STREQ(crossed.View().c_str(), "[0, -1, 1]");
    ASSERT_EQ(crossed.Magnitude(), v1.Magnitude() * v2.Magnitude());
  });
}

TEST(Vector, cross__parallel__zero) {
  Firefly::Vector v1{{1, 0, 0}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v1.Cross(v1).IsZero()); });
}

TEST(Vector, cross__regular) {
  using namespace testing;
  Firefly::Vector v1{{1, 3, 1}};
  Firefly::Vector v2{{1, 3, 4}};

  ASSERT_NO_THROW({
    auto crossed = v1.Cross(v2);

    ASSERT_TRUE(v1.IsOrthogonal(crossed));
    ASSERT_TRUE(v2.IsOrthogonal(crossed));
    ASSERT_FALSE(crossed.IsZero());

    auto angle =
        std::asin(crossed.Magnitude() / (v1.Magnitude() * v2.Magnitude()));

    ASSERT_THAT(angle, AllOf(Gt(-M_PI), Lt(M_PI)));
  });
}