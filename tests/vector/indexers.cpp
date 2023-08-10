#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(Vector, indexers__empty__error) {
  Firefly::Vector v{0};

  ASSERT_THROW({ auto _ = v[0]; }, std::length_error);
}

TEST(Vector, indexers__negative__error) {
  Firefly::Vector v{0};
  ASSERT_THROW({ auto _ = v[-1]; }, std::length_error);
}

TEST(Vector, indexers__valid_input__return_reference) {
  Firefly::Vector v{5};

  ASSERT_NO_THROW({
    ASSERT_EQ(v[3], 0);
    v[3] = 10;
    ASSERT_EQ(v[3], 10);
  });
}