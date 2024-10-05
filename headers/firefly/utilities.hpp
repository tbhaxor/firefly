#include "firefly/vector.hpp"

namespace firefly::utilities::vector {

/**
 * @brief Calculates the angle between two vectors in radians.
 *
 * This function computes the angle between two vectors, `v1` and `v2`, of the same length.
 * It uses the dot product and the norms of the vectors to determine the cosine of the angle.
 *
 * @tparam T Type of the first vector. Must be an arithmetic type.
 * @tparam U Type of the second vector. Must be an arithmetic type.
 * @tparam Length Length of both vectors.
 *
 * @param v1 First vector of type `firefly::vector<T, Length>`.
 * @param v2 Second vector of type `firefly::vector<U, Length>`.
 * @param delta A small tolerance value for numerical stability (default is 1e-6).
 *
 * @throws std::logic_error when norm is zero. This usually happens when zero vector is passed
 * @return The angle between the two vectors in radians. The result is clamped between -1.0 and 1.0.
 *
 * @note Only arithmetic types are allowed for T and U.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto angle_between(firefly::vector<T, Length> const &v1, firefly::vector<U, Length> const &v2,
                                           double delta = 1e-6) {
  static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "Only arithmetic types are allowed.");
  if (v1.norm() == 0 || v2.norm() == 0) {
    return M_PI_2;
  }

  auto rad = std::acos(std::clamp((v1.to_normalized() * v2.to_normalized()) / 1, -1.0, 1.0));
  return rad < delta ? 0.0 : rad;
}

/**
 * @brief Checks if two vectors are anti-parallel.
 *
 * Two vectors are considered anti-parallel if they are in opposite direction.
 *
 * @tparam T Type of the first vector.
 * @tparam U Type of the second vector.
 * @tparam Length Length of both vectors.
 *
 * @param v1 First vector of type `firefly::vector<T, Length>`.
 * @param v2 Second vector of type `firefly::vector<U, Length>`.
 *
 * @throws std::logic_error when norm is zero. This usually happens when zero vector is passed
 * @return true if the vectors are anti-parallel, false otherwise.
 *
 * @note Only arithmetic types are allowed for T and U.
 */
template <vector_type T, vector_type U, std::size_t Length>
bool are_anti_parallel(firefly::vector<T, Length> const &v1, firefly::vector<U, Length> const &v2) {
  static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "Only arithmetic types are allowed.");
  return v1.to_normalized() == -v2.to_normalized();
}

/**
 * @brief Checks if two vectors are parallel.
 *
 * Two vectors are considered parallel if they are same or opposite directions.
 *
 * @tparam T Type of the first vector.
 * @tparam U Type of the second vector.
 * @tparam Length Length of both vectors.
 *
 * @param v1 First vector of type `firefly::vector<T, Length>`.
 * @param v2 Second vector of type `firefly::vector<U, Length>`.
 *
 * @throws std::logic_error when norm is zero. This usually happens when zero vector is passed
 * @return true if the vectors are parallel, false otherwise.
 *
 * @note Only arithmetic types are allowed for T and U.
 */
template <vector_type T, vector_type U, std::size_t Length>
bool are_parallel(firefly::vector<T, Length> const &v1, firefly::vector<U, Length> const &v2) {
  static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "Only arithmetic types are allowed.");
  return (v1.to_normalized() == v2.to_normalized()) || are_anti_parallel(v1, v2);
}

/**
 * @brief Checks if two- vectors are orthogonal.
 *
 * Two vectors are considered orthogonal if the angle between them is close to 90 degrees (or π/2 radians).
 *
 * @tparam T Type of the first vector.
 * @tparam U Type of the second vector.
 * @tparam Length Length of both vectors.

 * @param v1 First vector of type `firefly::vector<T, Length>`.
 * @param v2 Second vector of type `firefly::vector<U, Length>`.
 * @param delta A small tolerance value for numerical stability (default is 1e-6).

 * @throws std::logic_error when norm is zero. This usually happens when zero vector is passed
 * @return true if the vectors are orthogonal, false otherwise.
 *
 * @note Only arithmetic types are allowed for T and U.
 */
template <vector_type T, vector_type U, std::size_t Length>
bool are_orthogonal(firefly::vector<T, Length> const &v1, firefly::vector<U, Length> const &v2, double delta = 1e-6) {
  static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "Only arithmetic types are allowed.");
  return std::fabs(angle_between(v1, v2) - M_PI_2) < delta;
}

/**
 * @brief Computes the area of the parallelogram formed by two vectors.
 *
 * @tparam T The type of the elements in the first vector.
 * @tparam U The type of the elements in the second vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param v1 The first vector.
 * @param v2 The second vector.
 *
 * @return The area of the parallelogram formed by v1 and v2.
 *
 * @note Only arithmetic types are allowed for T and U.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto area_parallelogram(firefly::vector<T, Length> const &v1,
                                                firefly::vector<U, Length> const &v2) {
  static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "Only arithmetic types are allowed.");
  return v1.cross(v2).norm();
}

/**
 * @brief Computes the area of the triangle formed by two vectors.
 *
 * @tparam T The type of the elements in the first vector.
 * @tparam U The type of the elements in the second vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param v1 The first vector.
 * @param v2 The second vector.
 *
 * @return The area of the triangle formed by v1 and v2.
 *
 * @note Only arithmetic types are allowed for T and U.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto area_triangle(firefly::vector<T, Length> const &v1, firefly::vector<U, Length> const &v2) {
  static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>, "Only arithmetic types are allowed.");
  return area_parallelogram(v1, v2) / 2;
}

/**
 * @brief Projects a source vector onto a target vector.
 *
 * @tparam T The type of the elements in the source vector.
 * @tparam U The type of the elements in the target vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param source_vector The vector being projected.
 * @param target_vector The vector onto which the source_vector is projected.
 *
 * @return The projection of source_vector onto target_vector.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto projection(firefly::vector<T, Length> const &source_vector,
                                        firefly::vector<U, Length> const &target_vector) {
  return target_vector * ((source_vector * target_vector) / (target_vector * target_vector));
}

/**
 * @brief Rejects a source vector from a target vector.
 *
 * @tparam T The type of the elements in the source vector.
 * @tparam U The type of the elements in the target vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param source_vector The vector being rejected.
 * @param target_vector The vector from which the source_vector is rejected.
 *
 * @return The component of source_vector orthogonal to target_vector.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto rejection(firefly::vector<T, Length> const &source_vector,
                                       firefly::vector<U, Length> const &target_vector) {
  return source_vector - projection(source_vector, target_vector);
}

/**
 * @brief Computes the Euclidean distance between two vectors.
 *
 * @tparam T The type of the elements in the first vector.
 * @tparam U The type of the elements in the second vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param vector_a The first vector.
 * @param vector_b The second vector.
 *
 * @return The distance between vector_a and vector_b.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto distance(firefly::vector<T, Length> const &vector_a,
                                      firefly::vector<U, Length> const &vector_b) {
  return (vector_a - vector_b).norm();
}

/**
 * @brief Reflects a source vector across a target vector.
 *
 * @tparam T The type of the elements in the source vector.
 * @tparam U The type of the elements in the target vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param source_vector The vector being reflected.
 * @param target_vector The vector across which the source_vector is reflected.
 *
 * @return The reflected vector of source_vector across target_vector.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto reflection(firefly::vector<T, Length> const &source_vector,
                                        firefly::vector<U, Length> const &target_vector) {
  return projection(source_vector, target_vector) * 2 - source_vector;
}

/**
 * @brief Rotates a 2D vector by a given angle (in radians).
 *
 * @tparam T The type of the elements in the vector.
 *
 * @param vector The 2D vector to rotate.
 * @param angle_rad The angle in radians to rotate the vector.
 *
 * @return The rotated vector.
 */
template <vector_type T>
[[nodiscard]] constexpr auto rotate_2d(firefly::vector<T, 2> const &vector, double angle_rad) {
  T x = vector[0] * std::cos(angle_rad) - vector[1] * std::sin(angle_rad);
  T y = vector[0] * std::sin(angle_rad) + vector[1] * std::cos(angle_rad);
  return firefly::vector<T, 2>{x, y};
}

/**
 * @brief Computes the scalar projection of a source vector onto a target
 * vector.
 *
 * @tparam T The type of the elements in the source vector.
 * @tparam U The type of the elements in the target vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param source_vector The vector being projected.
 * @param target_vector The vector onto which the source_vector is projected.
 *
 * @return The scalar projection of source_vector onto target_vector.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto scalar_projection(firefly::vector<T, Length> const &source_vector,
                                               firefly::vector<U, Length> const &target_vector) {
  return source_vector.dot(target_vector) / target_vector.norm();
}

/**
 * @brief Performs linear interpolation (Lerp) between two vectors.
 *
 * @tparam T The type of the elements in the first vector.
 * @tparam U The type of the elements in the second vector.
 * @tparam Length The number of dimensions of the vectors.
 *
 * @param vector_a The first vector.
 * @param vector_b The second vector.
 * @param t The interpolation parameter, typically in the range [0, 1].
 *
 * @return The interpolated vector between vector_a and vector_b.
 */
template <vector_type T, vector_type U, std::size_t Length>
[[nodiscard]] constexpr auto lerp(firefly::vector<T, Length> const &vector_a,
                                  firefly::vector<U, Length> const &vector_b, double t) {
  return vector_a * (1 - t) + vector_b * t;
}

} // namespace firefly::utilities::vector