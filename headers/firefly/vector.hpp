#pragma once

#include <cstddef>
#include <ostream>
#include <vector>

#ifdef DOUBLE_PRECISION
using Real = double;
#else
using Real = float;
#endif

namespace Firefly {

/**
 * @class Vector
 * @brief Represents a mathematical vector in n-dimensional space.
 *
 * The Vector class provides various operations on vectors, such as addition,
 * subtraction, scaling, dot product, cross product, normalization, angle
 * calculation, and more.
 */
class Vector {
  using VectorType = std::vector<Real>;

  VectorType m_vec;
  Vector(Vector &&) noexcept;

public:
  Vector() = delete;

  ~Vector() = default;

  /**
   * @brief Constructs a vector of a specific size.
   * @param _size The size of the vector.
   */
  explicit Vector(std::size_t _size);
  /**
   * @brief Constructs a vector from a given VectorType (std::vector).
   * @param _vec The VectorType representing the vector.
   */
  explicit Vector(VectorType const &_vec);
  /**
   * @brief Copy constructor to create a new vector from an existing one.
   * @param _f The source vector to copy from.
   */
  Vector(Vector const &_fvec);

  /**
   * @brief Returns a string representation of the vector.
   * @return A string representation of the vector.
   */
  [[nodiscard]] std::string View() const;
  /**
   * @brief Overloaded stream insertion operator to print the vector to an
   * output stream.
   * @param os The output stream.
   * @param _fvec The vector to print.
   * @return The output stream after printing the vector.
   */
  friend std::ostream &operator<<(std::ostream &os, Vector const &_fvec);

  /**
   * @brief Retrieves the value at a specific index in the vector (getter).
   * @param idx The index of the element to retrieve.
   * @return The value at the specified index.
   */
  [[nodiscard]] Real At(std::size_t idx) const;
  /**
   * @brief Retrieves a reference to the value at a specific index in the
   * vector (setter).
   * @param idx The index of the element to retrieve.
   * @return A reference to the value at the specified index.
   */
  [[nodiscard]] Real &At(std::size_t idx);
  /**
   * @brief Overloaded subscript operator to access the value at a specific
   * index (getter).
   * @param idx The index of the element to retrieve.
   * @return The value at the specified index.
   */
  [[nodiscard]] Real operator[](std::size_t idx) const;
  /**
   * @brief Overloaded subscript operator to access the value at a specific
   * index (setter).
   * @param idx The index of the element to retrieve.
   * @return A reference to the value at the specified index.
   */
  [[nodiscard]] Real &operator[](std::size_t idx);

  /**
   * @brief Returns the size (number of elements) of the vector.
   * @return The size of the vector.
   */
  [[nodiscard]] std::size_t Size() const;

  /**
   * @brief Performs element-wise vector addition with another vector.
   * @param _fvec The vector to add.
   * @return New vector containing the result of the addition.
   */
  [[nodiscard]] Vector Add(Vector const &_fvec) const;
  /**
   * @brief Performs scalar addition (using broadcasting) with a real value.
   * @param _scalar The scalar value to add.
   * @return New vector containing the result of the addition.
   */
  [[nodiscard]] Vector Add(Real const &_scalar) const;
  /**
   * @brief Overloaded operator to perform vector addition. Internally calls
   * Add().
   * @param _fvec The vector to add.
   * @return New vector containing the result of the addition.
   */
  [[nodiscard]] Vector operator+(Vector const &_fvec) const;
  /**
   * @brief Overloaded operator to perform scalar addition. Internally calls
   * Add().
   * @param _scalar The scalar value to add.
   * @return New vector containing the result of the addition.
   */
  [[nodiscard]] Vector operator+(Real const &_scalar) const;

  /**
   * @brief Performs element-wise scaling of vector by a real value.
   * @param _scalar The scalar value to scale the vector by.
   * @return New vector containing the scaled result.
   */
  [[nodiscard]] Vector Scale(Real const &_fvec) const;

  /**
   * @brief Overloaded operator to perform vector scaling.
   * @param _scalar The scalar value to scale the vector by.
   * @return New vector containing the scaled result.
   */
  [[nodiscard]] Vector operator*(Real const &_scalar) const;

  /**
   * @brief Performs element-wise vector subtraction with another vector.
   * @param _fvec The vector to subtract.
   * @return New vector containing the result of the subtraction.
   */
  [[nodiscard]] Vector Subtract(Vector const &_fvec) const;
  /**
   * @brief Performs scalar subtraction (using broadcasting) with a real value.
   * @param _scalar The scalar value to subtract.
   * @return New vector containing the result of the subtraction.
   */
  [[nodiscard]] Vector Subtract(Real const &_scalar) const;
  /**
   * @brief Overloaded operator to perform vector subtraction. Internally it
   * will use Subtract().
   * @param _fvec The vector to subtract.
   * @return New vector containing the result of the subtraction.
   */
  [[nodiscard]] Vector operator-(Vector const &_fvec) const;
  /**
   * @brief Overloaded operator to perform scalar subtraction. Internally it
   * will use Subtract().
   * @param _scalar The scalar value to subtract.
   * @return New vector containing the result of the subtraction.
   */
  [[nodiscard]] Vector operator-(Real const &_scalar) const;

  /**
   * @brief Overload unary negation operator to negate the original vector,
   * giving anti-parallel vector.
   *
   * It negates all components of the vector, effectively reversing its
   * direction while keeping its magnitude unchanged. The resulting vector
   * points in the opposite direction of the original vector.
   *
   * For a 2D vector v = (x, y), the negation -v = (-x, -y).
   * For a 3D vector v = (x, y, z), the negation -v = (-x, -y, -z).
   *
   * @note The original Vector object remains unchanged after using this
   * operator.
   *
   * @return A new Vector object with all components negated.
   */
  [[nodiscard]] Vector operator-() const;

  /**
   * @brief Calculates the dot product between this vector and another vector.
   * @param _fvec The other vector to calculate the dot product with.
   * @return The dot product value.
   */
  [[nodiscard]] Real Dot(Vector const &_fvec) const;

  /**
   * @brief Calculates the cross product using Levi-Civita symbol between this
   * vector and another vector. Both vectors must have three dimensions.
   *
   * @param _fvec The other vector to calculate the cross product with.
   * @return New vector containing the result of the
   * cross product.
   * @see https://en.wikipedia.org/wiki/Levi-Civita_symbol#Vector_cross_product
   */
  [[nodiscard]] Vector Cross(Vector const &_fvec) const;

  /**
   * @brief Calculates the sum of all elements in the vector.
   * @return The sum of all elements.
   */
  [[nodiscard]] Real ElemSum() const;

  /**
   * @brief Calculates the magnitude (Euclidean norm) of the vector.
   * @return The magnitude of the vector.
   */
  [[nodiscard]] Real Magnitude() const;

  /**
   * @brief Scales the vector 1/|v| and returns a new vector that is the
   * normalized version (|v| = 1) of this vector.
   * @return A new normalized vector.
   */
  [[nodiscard]] Vector Normalize() const;

  /**
   * @brief Calculates the angle between this vector and another vector in
   * radians.
   * @param _fvec The other vector to calculate the angle with.
   * @return The angle between the two vectors in radians.
   */
  [[nodiscard]] Real AngleWith(Vector const &_fvec) const;

  /**
   * @brief Checks if this vector is the same as another vector.
   *
   * This function compares the current vector with another vector to determine
   * if they are the same. The comparison is based on the values of the vector's
   * components.
   *
   * @param _fvec Another vector to compare with.
   * @return Returns true if the vectors are the same, otherwise false.
   */
  [[nodiscard]] bool IsSame(Vector const &_fvec) const;

  /**
   * @brief Compares two vectors for equality.
   *
   * This operator compares the current vector with another vector to check for
   * equality. It internally calls the IsSame function to perform the
   * comparison. The comparison is based on the values of the vector's
   * components.
   *
   * @param _fvec Another vector to compare with.
   * @return Returns true if the vectors are equal, otherwise false.
   * @see IsSame
   */
  [[nodiscard]] bool operator==(Vector const &_fvec) const;

  /**
   * @brief Checks if the vector is sparse.
   *
   * A vector is considered sparse if the count of zero elements is greater that
   * the count of non-zero elements. This function calculates the counts of zero
   * and non-zero elements in the vector and compares them to determine
   * sparsity.
   *
   * @return Returns true if the vector is sparse, i.e., the count of zero
   * elements is greater than or equal to the count of non-zero elements.
   */
  [[nodiscard]] bool IsSparse() const;

  /**
   * @brief Checks if the vector is a zero vector (all elements are zero).
   * @return True if the vector is a zero vector, otherwise false.
   */
  [[nodiscard]] bool IsZero() const;

  /**
   * @brief Checks if the vector is a unit vector (normalized with a magnitude
   * of 1).
   * @return True if the vector is a unit vector, otherwise false.
   */
  [[nodiscard]] bool IsNormalized() const;
  /**
   * @brief Checks if this vector is parallel to another vector.
   *
   * Two vectors are parallel if their direction ratios are proportional.
   *
   * @param _fvec Another vector to compare with.
   * @return Returns true if the vectors are parallel, otherwise false.
   * @note If one of the vectors is the zero vector, they are considered
   * parallel.
   * @see https://www.cuemath.com/geometry/direction-ratio/
   */
  [[nodiscard]] bool IsParallel(Vector const &_fvec) const;
  /**
   * @brief Checks if this vector is orthogonal (perpendicular) to another
   * vector.
   *
   * Two vectors are considered orthogonal if their dot product is 0,
   * indicating a 90-degree angle between them.
   *
   * @param _fvec The other vector to check for orthogonality.
   * @return True if the vectors are orthogonal, otherwise false.
   */
  [[nodiscard]] bool IsOrthogonal(Vector const &_fvec) const;

  /**
   * @brief Calculates the area of the parallelogram spanned by this vector and
   * another vector.
   * @param _fvec The other vector forming the parallelogram.
   * @return The area of the parallelogram.
   * @see https://www.cuemath.com/measurement/area-of-parallelogram/
   */
  [[nodiscard]] Real ParallelogramArea(Vector const &_fvec) const;
  /**
   * @brief Calculates the area of the triangle formed by this vector and
   * another vector.
   * @param _fvec The other vector forming the triangle.
   * @return The area of the triangle.
   */
  [[nodiscard]] Real TriangleArea(Vector const &_fvec) const;
};

} // namespace Firefly