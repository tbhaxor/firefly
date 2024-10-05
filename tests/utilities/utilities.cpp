#include "firefly/utilities.hpp"
#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST(utilities, angle_between__normal_vectors_in_radians) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::angle_between(v1, v2)), double>));
  ASSERT_NEAR(firefly::utilities::vector::angle_between(v1, v2), 0.17985349979247847, 1e-6);
}

TEST(utilities, angle_between__orthogonal_vectors_is_90) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::angle_between(v1, v2)), double>));
  ASSERT_DOUBLE_EQ(firefly::utilities::vector::angle_between(v1, v2), M_PI_2);
}

TEST(utilities, angle_between__parallel_vectors_0) {
  firefly::vector<int, 2> v1{1, 2};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::angle_between(v1, v1)), double>));
  ASSERT_NEAR(firefly::utilities::vector::angle_between(v1, v1), 0, 1e-05);
}

TEST(utilities, are_orthogonal__normal_orthogonal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_orthogonal(v1, v2)), bool>));
  ASSERT_TRUE(firefly::utilities::vector::are_orthogonal(v1, v2));
}

TEST(utilities, are_orthogonal__normal_non_orthogonal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_orthogonal(v1, v2)), bool>));
  ASSERT_FALSE(firefly::utilities::vector::are_orthogonal(v1, v2));
}

TEST(utilities, are_orthogonal__one_vector_is_zero) {
  firefly::vector<int, 2> v1{0, 0};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_orthogonal(v1, v2)), bool>));
  ASSERT_TRUE(firefly::utilities::vector::are_orthogonal(v1, v2));
}

TEST(utilities, are_orthogonal__both_vectors_are_zero) {
  firefly::vector<int, 2> v1{0, 0};
  firefly::vector<int, 2> v2{0, 0};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_orthogonal(v1, v2)), bool>));
  ASSERT_TRUE(firefly::utilities::vector::are_orthogonal(v1, v2));
}

TEST(utilities, are_parallel__normal_parallel_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{2, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_parallel(v1, v2)), bool>));
  ASSERT_TRUE(firefly::utilities::vector::are_parallel(v1, v2));
}

TEST(utilities, are_parallel__normal_anti_parallel_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-2, -4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_parallel(v1, v2)), bool>));
  ASSERT_TRUE(firefly::utilities::vector::are_parallel(v1, v2));
}

TEST(utilities, are_parallel__normal_non_parallel_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_parallel(v1, v2)), bool>));
  ASSERT_FALSE(firefly::utilities::vector::are_parallel(v1, v2));
}

TEST(utilities, are_parallel__one_vector_is_zero_throws_logic_error) {
  firefly::vector<int, 2> v1{0, 0};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_parallel(v1, v2)), bool>));
  ASSERT_THROW({ firefly::utilities::vector::are_parallel(v1, v2); }, std::logic_error);
}

TEST(utilities, are_parallel__both_vectors_are_zero_throws_logic_error) {
  firefly::vector<int, 2> v1{0, 0};
  firefly::vector<int, 2> v2{0, 0};

  ASSERT_THROW({ firefly::utilities::vector::are_parallel(v1, v2); }, std::logic_error);
}

TEST(utilities, are_anti_parallel__normal_anti_parallel_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-2, -4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_anti_parallel(v1, v2)), bool>));
  ASSERT_TRUE(firefly::utilities::vector::are_anti_parallel(v1, v2));
}

TEST(utilities, are_anti_parallel__normal_parallel_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{2, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_anti_parallel(v1, v2)), bool>));
  ASSERT_FALSE(firefly::utilities::vector::are_anti_parallel(v1, v2));
}

TEST(utilities, are_anti_parallel__normal_non_parallel_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_anti_parallel(v1, v2)), bool>));
  ASSERT_FALSE(firefly::utilities::vector::are_anti_parallel(v1, v2));
}

TEST(utilities, are_anti_parallel__one_vector_is_zero_throws_logic_error) {
  firefly::vector<int, 2> v1{0, 0};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::are_anti_parallel(v1, v2)), bool>));
  ASSERT_THROW({ firefly::utilities::vector::are_anti_parallel(v1, v2); }, std::logic_error);
}

TEST(utilities, are_anti_parallel__both_vectors_are_zero_throws_logic_error) {
  firefly::vector<int, 2> v1{0, 0};
  firefly::vector<int, 2> v2{0, 0};

  ASSERT_THROW({ firefly::utilities::vector::are_anti_parallel(v1, v2); }, std::logic_error);
}

TEST(utilities, area_parallelogram__normal_vectors) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<int, 3> v2{4, 5, 6};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::area_parallelogram(v1, v2)), double>));
  ASSERT_DOUBLE_EQ(firefly::utilities::vector::area_parallelogram(v1, v2), 7.3484692283495345);
}

TEST(utilities, area_parallelogram__parallel_vectors) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<int, 3> v2{2, 4, 6};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::area_parallelogram(v1, v2)), double>));
  ASSERT_DOUBLE_EQ(firefly::utilities::vector::area_parallelogram(v1, v2), 0);
}

TEST(utilities, area_triangle__normal_vectors) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<int, 3> v2{4, 5, 6};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::area_triangle(v1, v2)), double>));
  ASSERT_DOUBLE_EQ(firefly::utilities::vector::area_triangle(v1, v2), 3.6742346141747673);
}

TEST(utilities, area_triangle__parallel_vectors) {
  firefly::vector<int, 3> v1{1, 2, 3};
  firefly::vector<int, 3> v2{2, 4, 6};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::area_triangle(v1, v2)), double>));

  ASSERT_DOUBLE_EQ(firefly::utilities::vector::area_triangle(v1, v2), 0);
}

TEST(utilities, projection__normal_vectors) {
  firefly::vector<double, 2> v1{1, 2};
  firefly::vector<double, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::projection(v1, v2)), firefly::vector<double, 2>>));

  auto projection_v1_onto_v2 = firefly::utilities::vector::projection(v1, v2);
  ASSERT_DOUBLE_EQ(projection_v1_onto_v2[0], 1.32);
  ASSERT_DOUBLE_EQ(projection_v1_onto_v2[1], 1.76);
}

TEST(utilities, projection__orthogonal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::projection(v1, v2)), firefly::vector<int, 2>>));

  auto projection_v1_onto_v2 = firefly::utilities::vector::projection(v1, v2);
  ASSERT_DOUBLE_EQ(projection_v1_onto_v2[0], 0);
  ASSERT_DOUBLE_EQ(projection_v1_onto_v2[1], 0);
}

TEST(utilities, projection__complex_normal_vectors) {
  firefly::vector<std::complex<double>, 2> v1{std::complex<double>(1, 2), std::complex<double>(3, 4)};
  firefly::vector<std::complex<double>, 2> v2{std::complex<double>(5, 6), std::complex<double>(7, 8)};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::projection(v1, v2)),
                              firefly::vector<std::complex<double>, 2>>));

  auto projection_v1_onto_v2 = firefly::utilities::vector::projection(v1, v2);
  ASSERT_DOUBLE_EQ(std::real(projection_v1_onto_v2[0]), 1.7465961665565102);
  ASSERT_DOUBLE_EQ(std::imag(projection_v1_onto_v2[0]), 2.6313284864507605);
  ASSERT_DOUBLE_EQ(std::real(projection_v1_onto_v2[1]), 2.4627891606080636);
  ASSERT_DOUBLE_EQ(std::imag(projection_v1_onto_v2[1]), 3.5230667547918046);
}

TEST(utilities, rejection__normal_vectors) {
  firefly::vector<double, 2> v1{1, 2};
  firefly::vector<double, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rejection(v1, v2)), firefly::vector<double, 2>>));

  auto rejection_v1_onto_v2 = firefly::utilities::vector::rejection(v1, v2);
  ASSERT_DOUBLE_EQ(rejection_v1_onto_v2[0], -0.32);
  ASSERT_DOUBLE_EQ(rejection_v1_onto_v2[1], 0.24);
}

TEST(utilities, rejection__orthogonal_vectors) {
  firefly::vector<double, 2> v1{1, 2};
  firefly::vector<double, 2> v2{-8, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rejection(v1, v2)), firefly::vector<double, 2>>));

  auto rejection_v1_onto_v2 = firefly::utilities::vector::rejection(v1, v2);
  ASSERT_DOUBLE_EQ(rejection_v1_onto_v2[0], 1);
  ASSERT_DOUBLE_EQ(rejection_v1_onto_v2[1], 2);
}

TEST(utilities, rejection__complex_normal_vectors) {
  firefly::vector<std::complex<double>, 2> v1{{1, 2}, {3, 4}};
  firefly::vector<std::complex<double>, 2> v2{{5, 6}, {7, 8}};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rejection(v1, v2)),
                              firefly::vector<std::complex<double>, 2>>));

  auto rejection_v1_onto_v2 = firefly::utilities::vector::rejection(v1, v2);
  ASSERT_DOUBLE_EQ(std::real(rejection_v1_onto_v2[0]), -0.74659616655651018);
  ASSERT_DOUBLE_EQ(std::imag(rejection_v1_onto_v2[0]), -0.63132848645076045);
  ASSERT_DOUBLE_EQ(std::real(rejection_v1_onto_v2[1]), 0.53721083939193637);
  ASSERT_DOUBLE_EQ(std::imag(rejection_v1_onto_v2[1]), 0.47693324520819536);
}

TEST(utilities, distance__normal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::distance(v1, v2)), double>));

  ASSERT_DOUBLE_EQ(firefly::utilities::vector::distance(v1, v2), 2.8284271247461903);
}

TEST(utilities, distance__same_vectors) {
  firefly::vector<int, 2> v1{1, 2};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::distance(v1, v1)), double>));

  ASSERT_DOUBLE_EQ(firefly::utilities::vector::distance(v1, v1), 0);
}

TEST(utilities, distance__complex_normal_vectors) {
  firefly::vector<std::complex<double>, 2> v1{{1, 2}, {3, 4}};
  firefly::vector<std::complex<double>, 2> v2{{5, 6}, {7, 8}};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::distance(v1, v2)), double>));
  ASSERT_DOUBLE_EQ(firefly::utilities::vector::distance(v1, v2), 8);
}

TEST(utilities, distance__complex_same_vectors) {
  firefly::vector<std::complex<double>, 2> v1{{1, 2}, {3, 4}};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::distance(v1, v1)), double>));
  ASSERT_DOUBLE_EQ(firefly::utilities::vector::distance(v1, v1), 0);
}

TEST(utilities, reflection__normal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::reflection(v1, v2)), firefly::vector<int, 2>>));

  auto reflection_v1_onto_v2 = firefly::utilities::vector::reflection(v1, v2);
  ASSERT_DOUBLE_EQ(reflection_v1_onto_v2[0], -1);
  ASSERT_DOUBLE_EQ(reflection_v1_onto_v2[1], -2);
}

TEST(utilities, reflection__orthogonal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::reflection(v1, v2)), firefly::vector<int, 2>>));

  auto reflection_v1_onto_v2 = firefly::utilities::vector::reflection(v1, v2);
  ASSERT_DOUBLE_EQ(reflection_v1_onto_v2[0], -1);
  ASSERT_DOUBLE_EQ(reflection_v1_onto_v2[1], -2);
}

TEST(utilities, reflection__complex_normal_vectors) {
  firefly::vector<std::complex<double>, 2> v1{std::complex<double>(1, 2), std::complex<double>(3, 4)};
  firefly::vector<std::complex<double>, 2> v2{std::complex<double>(5, 6), std::complex<double>(7, 8)};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::reflection(v1, v2)),
                              firefly::vector<std::complex<double>, 2>>));

  auto reflection_v1_onto_v2 = firefly::utilities::vector::reflection(v1, v2);
  ASSERT_DOUBLE_EQ(std::real(reflection_v1_onto_v2[0]), 2.4931923331130204);
  ASSERT_DOUBLE_EQ(std::imag(reflection_v1_onto_v2[0]), 3.2626569729015209);
  ASSERT_DOUBLE_EQ(std::real(reflection_v1_onto_v2[1]), 1.9255783212161273);
  ASSERT_DOUBLE_EQ(std::imag(reflection_v1_onto_v2[1]), 3.0461335095836093);
}

TEST(utilities, rotate_2d__normal_vector) {
  firefly::vector<int, 2> v1{1, 2};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rotate_2d(v1, M_PI_2)), firefly::vector<int, 2>>));

  auto rotated_v1 = firefly::utilities::vector::rotate_2d(v1, M_PI_2);
  ASSERT_DOUBLE_EQ(rotated_v1[0], -2);
  ASSERT_DOUBLE_EQ(rotated_v1[1], 1);
}

TEST(utilities, rotate_2d__zero_vector) {
  firefly::vector<int, 2> v1{0, 0};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rotate_2d(v1, M_PI_2)), firefly::vector<int, 2>>));

  auto rotated_v1 = firefly::utilities::vector::rotate_2d(v1, M_PI_2);
  ASSERT_DOUBLE_EQ(rotated_v1[0], 0);
  ASSERT_DOUBLE_EQ(rotated_v1[1], 0);
}

TEST(utilities, rotate_2d__complex_vector) {
  firefly::vector<std::complex<double>, 2> v1{std::complex<double>(1, 2), std::complex<double>(3, 4)};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rotate_2d(v1, M_PI_2)),
                              firefly::vector<std::complex<double>, 2>>));

  auto rotated_v1 = firefly::utilities::vector::rotate_2d(v1, M_PI_2);
  ASSERT_DOUBLE_EQ(rotated_v1[0].real(), -3);
  ASSERT_DOUBLE_EQ(rotated_v1[0].imag(), -4);
  ASSERT_DOUBLE_EQ(rotated_v1[1].real(), 1);
  ASSERT_DOUBLE_EQ(rotated_v1[1].imag(), 2);
}

TEST(utilities, rotate_2d__complex_zero_vector) {
  firefly::vector<std::complex<double>, 2> v1{{0, 0}, {0, 0}};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::rotate_2d(v1, M_PI_2)),
                              firefly::vector<std::complex<double>, 2>>));

  auto rotated_v1 = firefly::utilities::vector::rotate_2d(v1, M_PI_2);
  ASSERT_DOUBLE_EQ(rotated_v1[0].real(), 0);
  ASSERT_DOUBLE_EQ(rotated_v1[0].imag(), 0);
  ASSERT_DOUBLE_EQ(rotated_v1[1].real(), 0);
  ASSERT_DOUBLE_EQ(rotated_v1[1].imag(), 0);
}

TEST(utilities, scalar_projection__normal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::scalar_projection(v1, v2)), double>));

  auto scalar_projection_v1_onto_v2 = firefly::utilities::vector::scalar_projection(v1, v2);
  ASSERT_DOUBLE_EQ(scalar_projection_v1_onto_v2, 2.2);
}

TEST(utilities, scalar_projection__orthogonal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{-8, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::scalar_projection(v1, v2)), double>));

  auto scalar_projection_v1_onto_v2 = firefly::utilities::vector::scalar_projection(v1, v2);
  ASSERT_DOUBLE_EQ(scalar_projection_v1_onto_v2, 0);
}

TEST(utilities, scalar_projection__complex_normal_vectors) {
  firefly::vector<std::complex<double>, 2> v1{std::complex<double>(1, 2), std::complex<double>(3, 4)};
  firefly::vector<std::complex<double>, 2> v2{std::complex<double>(5, 6), std::complex<double>(7, 8)};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::scalar_projection(v1, v2)), std::complex<double>>));

  auto scalar_projection_v1_onto_v2 = firefly::utilities::vector::scalar_projection(v1, v2);
  ASSERT_DOUBLE_EQ(std::real(scalar_projection_v1_onto_v2), -1.364576478442026);
  ASSERT_DOUBLE_EQ(std::imag(scalar_projection_v1_onto_v2), 5.1550666963365428);
}

TEST(utilities, lerp__normal_vectors) {
  firefly::vector<int, 2> v1{1, 2};
  firefly::vector<int, 2> v2{3, 4};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::lerp(v1, v2, 0.5)), firefly::vector<double, 2>>));

  auto lerp_v1_v2 = firefly::utilities::vector::lerp(v1, v2, 0.5);
  ASSERT_DOUBLE_EQ(lerp_v1_v2[0], 2);
  ASSERT_DOUBLE_EQ(lerp_v1_v2[1], 3);
}

TEST(utilities, lerp__complex_normal_vectors) {
  firefly::vector<std::complex<double>, 2> v1{std::complex<double>(1, 2), std::complex<double>(3, 4)};
  firefly::vector<std::complex<double>, 2> v2{std::complex<double>(5, 6), std::complex<double>(7, 8)};

  ASSERT_TRUE((std::is_same_v<decltype(firefly::utilities::vector::lerp(v1, v2, 0.5)),
                              firefly::vector<std::complex<double>, 2>>));

  auto lerp_v1_v2 = firefly::utilities::vector::lerp(v1, v2, 0.5);
  ASSERT_DOUBLE_EQ(lerp_v1_v2[0].real(), 3);
  ASSERT_DOUBLE_EQ(lerp_v1_v2[0].imag(), 4);
  ASSERT_DOUBLE_EQ(lerp_v1_v2[1].real(), 5);
  ASSERT_DOUBLE_EQ(lerp_v1_v2[1].imag(), 6);
}