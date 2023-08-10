#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, add__different_size__error) {
  Firefly::Vector v1{{1, 2, 3}};
  Firefly::Vector v2{{1, 2, 3, 4}};

  ASSERT_THROW({ auto _ = v1 + v2; }, std::length_error);
}

TEST(Vector, add__vector) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{{5, 6, 7, 8}};

  ASSERT_NO_THROW({
    auto v3 = v1 + v2;

    ASSERT_EQ(v3.Size(), v1.Size());
    for (auto i = 0; i < v2.Size(); i++) {
      ASSERT_EQ(v3.At(i), v1.At(i) + v2.At(i));
    }
  });
}

TEST(Vector, add__scalar) {
  Firefly::Vector v1{{1, 2, 3, 4}};

  ASSERT_NO_THROW({
    auto v2 = v1 + 10;

    ASSERT_EQ(v2.Size(), v1.Size());
    ASSERT_EQ(v2.At(0), 11);
    ASSERT_EQ(v2.At(1), 12);
    ASSERT_EQ(v2.At(2), 13);
    ASSERT_EQ(v2.At(3), 14);
  });
}
