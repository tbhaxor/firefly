#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, is_orthogonal__different_size__error) {
  Firefly::Vector v1{0};
  Firefly::Vector v2{10};

  ASSERT_THROW({ auto _ = v1.IsOrthogonal(v2); }, std::length_error);
}

TEST(Vector, is_orthogonal__empty__true) {
  Firefly::Vector v{0};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsOrthogonal(v)); });
}

TEST(Vector, is_orthogonal__zero__true) {
  Firefly::Vector v{10};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsOrthogonal(v)); });
}

TEST(Vector, is_orthogonal__non_zero_zero__true) {
  Firefly::Vector v1{3};
  Firefly::Vector v2{{1, 2, 3}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v1.IsOrthogonal(v2)); });
}

TEST(Vector, is_orthogonal__valid__true) {
  Firefly::Vector v1{{1, 0, 1}};
  Firefly::Vector v2{{{0, 1, 0}}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v1.IsOrthogonal(v2)); });
}

TEST(Vector, is_orthogonal__otherwise__false) {
  Firefly::Vector v1{{1, 0, 1}};
  Firefly::Vector v2{{{0, 1, 1}}};

  ASSERT_NO_THROW({ ASSERT_FALSE(v1.IsOrthogonal(v2)); });
}