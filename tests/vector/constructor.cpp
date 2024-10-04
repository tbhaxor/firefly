#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(vector, constructor__default_initialize_zeroes) {
  firefly::vector<int, 3> v1{};

  ASSERT_EQ(v1[0], 0);
  ASSERT_EQ(v1[1], 0);
  ASSERT_EQ(v1[2], 0);
}

TEST(vector, constructor__throws_when_list_length_does_not_match_template) {
  ASSERT_THROW(({ firefly::vector<int, 2> v1{1, 2, 3}; }), std::out_of_range);
}

TEST(vector, constructor__does_not_throw_with_valid_length) {
  ASSERT_NO_THROW(({ firefly::vector<int, 2> v1{1, 2}; }));
}

TEST(vector, constructor__value_initizes_with_that_values) {
  firefly::vector<float, 3> v1(3);

  ASSERT_EQ(v1[0], 3);
  ASSERT_EQ(v1[1], 3);
  ASSERT_EQ(v1[2], 3);
}
