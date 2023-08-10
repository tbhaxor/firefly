#include <cmath>
#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, subtract__different_size__error) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{1, 2, 3}};

  ASSERT_THROW({ auto _ = v1 - v2; }, std::length_error);
}

TEST(Vector, subtract__same__zero) {
  Firefly::Vector v1{{1, 2, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_TRUE((v1 - v1).IsZero()); });
}

TEST(Vector, subtract__different__non_zero) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{1, 3, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_FALSE((v1 - v2).IsZero()); });
}

TEST(Vector, subtract__scalar__element_wise) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_NO_THROW({
    auto sub = v - 1;
    for (auto i = 0; i < v.Size(); i++) {
      ASSERT_EQ(v[i] - 1, sub[i]);
    }
  });
}
