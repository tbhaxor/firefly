#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, is_sparse__empty__error) {
  Firefly::Vector v{0};

  ASSERT_THROW({ auto _ = v.IsSparse(); }, std::length_error);
}

TEST(Vector, is_sparse__zero__true) {
  Firefly::Vector v{10};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsSparse()); });
}

TEST(Vector, is_sparse__all_non_zero__false) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_NO_THROW({ ASSERT_FALSE(v.IsSparse()); });
}

TEST(Vector, is_sparse__zeros_gt_non_zero__true) {
  Firefly::Vector v{{1, 2, 0, 0, 0}};

  ASSERT_NO_THROW({ ASSERT_TRUE(v.IsSparse()); });
}

TEST(Vector, is_sparse__zeros_lt_non_zero__false) {
  Firefly::Vector v{{1, 2, 3, 0, 0}};

  ASSERT_NO_THROW({ ASSERT_FALSE(v.IsSparse()); });
}

TEST(Vector, is_sparse__zeros_eq_non_zero__false) {
  Firefly::Vector v{{1, 2, 3, 0, 0, 0}};

  ASSERT_NO_THROW({ ASSERT_FALSE(v.IsSparse()); });
}
