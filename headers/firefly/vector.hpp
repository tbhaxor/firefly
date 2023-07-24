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

public:
  Vector(Vector &&) = delete;
  Vector() = delete;

  ~Vector() = default;

  /**
   * @brief Constructs a vector of a specific size.
   * @param _size The size of the vector.
   */
  Vector(std::size_t _size);
  /**
   * @brief Constructs a vector from a given VectorType (std::vector).
   * @param _vec The VectorType representing the vector.
   */
  Vector(VectorType const &_vec);
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
   * @brief Retrieves the value at a specific index in the vector (const
   * version).
   * @param idx The index of the element to retrieve.
   * @return The value at the specified index.
   */
  [[nodiscard]] Real At(std::size_t idx) const;
  /**
   * @brief Retrieves a reference to the value at a specific index in the
   * vector.
   * @param idx The index of the element to retrieve.
   * @return A reference to the value at the specified index.
   */
  [[nodiscard]] Real &At(std::size_t idx);
  /**
   * @brief Overloaded subscript operator to access the value at a specific
   * index (const version).
   * @param idx The index of the element to retrieve.
   * @return The value at the specified index.
   */
  [[nodiscard]] Real operator[](std::size_t idx) const;
  /**
   * @brief Overloaded subscript operator to access the value at a specific
   * index.
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
   * @brief Returns the rank (dimensionality) of the vector. It is same as
   * Size() method.
   * @return The rank of the vector.
   */
  [[nodiscard]] std::size_t Rank() const;

  /**
   * @brief Performs vector addition with another vector and returns the result
   * as a new vector.
   * @param _fvec The vector to add.
   * @return A unique pointer to the new vector containing the result of the
   * addition.
   */
  [[nodiscard]] Vector &Add(Vector const &_fvec) const;
  /**
   * @brief Performs scalar addition with a real value and returns the result as
   * a new vector.
   * @param _scalar The scalar value to add.
   * @return A unique pointer to the new vector containing the result of the
   * addition.
   */
  [[nodiscard]] Vector &Add(Real const &_scalar) const;
  /**
   * @brief Overloaded operator to perform vector addition.
   * @param _fvec The vector to add.
   * @return A unique pointer to the new vector containing the result of the
   * addition.
   */
  [[nodiscard]] Vector &operator+(Vector const &_fvec) const;
  /**
   * @brief Overloaded operator to perform scalar addition.
   * @param _scalar The scalar value to add.
   * @return A unique pointer to the new vector containing the result of the
   * addition.
   */
  [[nodiscard]] Vector &operator+(Real const &_scalar) const;
  /**
   * @brief Overloaded prefix increment operator to increment all elements of
   * the vector by one.
   * @return A unique pointer to the new vector with incremented elements.
   */
  [[nodiscard]] Vector &operator++() const;

  /**
   * @brief Performs vector scaling by a real value and returns the result as a
   * new vector.
   * @param _scalar The scalar value to scale the vector by.
   * @return A unique pointer to the new vector containing the scaled result.
   */
  [[nodiscard]] Vector &Scale(Real const &_fvec) const;

  /**
   * @brief Overloaded operator to perform vector scaling.
   * @param _scalar The scalar value to scale the vector by.
   * @return A unique pointer to the new vector containing the scaled result.
   */
  [[nodiscard]] Vector &operator*(Real const &_scalar) const;

  /**
   * @brief Performs vector subtraction with another vector and returns the
   * result as a new vector.
   * @param _fvec The vector to subtract.
   * @return A unique pointer to the new vector containing the result of the
   * subtraction.
   */
  [[nodiscard]] Vector &Subtract(Vector const &_fvec) const;
  /**
   * @brief Performs scalar subtraction with a real value and returns the result
   * as a new vector.
   * @param _scalar The scalar value to subtract.
   * @return A unique pointer to the new vector containing the result of the
   * subtraction.
   */
  [[nodiscard]] Vector &Subtract(Real const &_scalar) const;
  /**
   * @brief Overloaded operator to perform vector subtraction.
   * @param _fvec The vector to subtract.
   * @return A unique pointer to the new vector containing the result of the
   * subtraction.
   */
  [[nodiscard]] Vector &operator-(Vector const &_fvec) const;
  /**
   * @brief Overloaded operator to perform scalar subtraction.
   * @param _scalar The scalar value to subtract.
   * @return A unique pointer to the new vector containing the result of the
   * subtraction.
   */
  [[nodiscard]] Vector &operator-(Real const &_scalar) const;
  /**
   * @brief Overloaded prefix decrement operator to decrement all elements of
   * the vector by one.
   * @return A unique pointer to the new vector with decremented elements.
   */
  [[nodiscard]] Vector &operator--() const;

  /**
   * @brief Calculates the dot product between this vector and another vector.
   * @param _fvec The other vector to calculate the dot product with.
   * @return The dot product value.
   */
  [[nodiscard]] Real Dot(Vector const &_fvec) const;

  /**
   * @brief Calculates the cross product between this vector and another vector.
   * Both vectors must have three dimensions.
   * @param _fvec The other vector to calculate the cross product with.
   * @return A unique pointer to the new vector containing the result of the
   * cross product.
   */
  [[nodiscard]] Vector &Cross(Vector const &_fvec) const;

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
   * @brief Returns a new vector that is the normalized version of this vector.
   * @return A unique pointer to the new normalized vector.
   */
  [[nodiscard]] Vector &Normalize() const;

  /**
   * @brief Calculates the angle between this vector and another vector in
   * radians.
   * @param _fvec The other vector to calculate the angle with.
   * @return The angle between the two vectors in radians.
   */
  [[nodiscard]] Real AngleWith(Vector const &_fvec) const;

  /**
   * @brief Checks if the vector is a zero vector (all elements are zero).
   * @return True if the vector is a zero vector, otherwise false.
   */
  [[nodiscard]] bool IsZero();

  /**
   * @brief Checks if the vector is a unit vector (normalized with a magnitude
   * of 1).
   * @return True if the vector is a unit vector, otherwise false.
   */
  [[nodiscard]] bool IsNormalized();
  /**
   * @brief Checks if this vector is parallel to another vector.
   *
   * Two vectors are considered parallel if their direction is the
   * same or opposite. To determine parallelism, the function calculates the
   * angle between the vectors and checks if it is either 0 degrees or 180
   * degrees (pi radians).
   *
   * @param _fvec The other vector to check for parallelism.
   * @return True if the vectors are parallel, otherwise false.
   */
  [[nodiscard]] bool IsParallel(Vector const &_fvec);
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
  [[nodiscard]] bool IsOrthogonal(Vector const &_fvec);

  /**
   * @brief Calculates the area of the parallelogram spanned by this vector and
   * another vector.
   * @param _fvec The other vector forming the parallelogram.
   * @return The area of the parallelogram.
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