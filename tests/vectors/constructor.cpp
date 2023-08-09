#include <vector>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(Vector, zero_size_instantiation) {
  Firefly::Vector v{0};

  ASSERT_EQ(v.Size(), 0);
  ASSERT_TRUE(v.IsZero());
}

TEST(Vector, nonzero_size_instantiation) {
  Firefly::Vector v{10};

  ASSERT_EQ(v.Size(), 10);
  ASSERT_TRUE(v.IsZero());
}

TEST(Vector, std_vector_initilization) {
  Firefly::Vector v{{1, 2, 3, 4}};

  ASSERT_EQ(v.Size(), 4);
  ASSERT_EQ(v.At(0), 1);
}

TEST(Vector, firefly_vector_initilization) {
  Firefly::Vector v1{{1, 2, 3, 4}};
  Firefly::Vector v2{v1};

  ASSERT_EQ(v1.Size(), v2.Size());
  ASSERT_TRUE(v1 == v2);
}

TEST(Vector, private_copy_initialization) {
  Firefly::Vector v1{10};
  Firefly::Vector v2{10};

  ASSERT_NO_THROW({
    auto v3 = v1 + v2;
    ASSERT_TRUE(v3.IsZero());
  });
}
