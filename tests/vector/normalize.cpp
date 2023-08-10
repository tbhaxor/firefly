#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, normalize__empty__error) {
  Firefly::Vector v{0};

  ASSERT_THROW({ auto _ = v.Normalize(); }, std::logic_error);
}

TEST(Vector, normalize__zero__error) {
  Firefly::Vector v{10};

  ASSERT_THROW({ auto _ = v.Normalize(); }, std::logic_error);
}

TEST(Vector, normalize__regular) {
  Firefly::Vector v{{3, 4}};

  ASSERT_NO_THROW({
    ASSERT_EQ(v.Normalize().Magnitude(), 1);
    ASSERT_EQ(v.Normalize(), v * (1 / v.Magnitude()));
  });
}
