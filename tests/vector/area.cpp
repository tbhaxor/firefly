#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, parallelogram_area__non_3d__error) {
  Firefly::Vector v{2};

  ASSERT_THROW({ auto _ = v.ParallelogramArea(v); }, std::length_error);
}

TEST(Vector, parallelogram_area__orthogonal__rect_area) {
  Firefly::Vector v1{{1, 0, 1}};
  Firefly::Vector v2{{0, 1, 0}};

  ASSERT_NO_THROW({
    ASSERT_EQ(v1.ParallelogramArea(v2), v1.Magnitude() * v2.Magnitude());
  });
}

TEST(Vector, parallelogram_area__parallel__0) {
  Firefly::Vector v1{{1, 0, 1}};
  auto v2 = v1 * 10;

  ASSERT_NO_THROW({ ASSERT_EQ(v1.ParallelogramArea(v2), 0); });
}

TEST(Vector, parallelogram_area__regular__cross_mag) {
  Firefly::Vector v1{{1, 0, 3}};
  Firefly::Vector v2{{1, 0, 1}};

  ASSERT_NO_THROW(
      { ASSERT_EQ(v1.ParallelogramArea(v2), v1.Cross(v2).Magnitude()); });
}

TEST(Vector, triangle_area__regular__half_parallelogram) {
  Firefly::Vector v1{{1, 0, 3}};
  Firefly::Vector v2{{1, 0, 1}};

  ASSERT_NO_THROW(
      { ASSERT_EQ(v1.TriangleArea(v2), v1.ParallelogramArea(v2) / 2); });
}