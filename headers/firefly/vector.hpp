#pragma once

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstddef>
#include <initializer_list>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <type_traits>

namespace firefly {

/**
 * @brief Customised common_type implementation that handles cases where one or both types may be arithmetic or
 * std::complex.
 *
 * This behaves like std::common_type but adds special handling when either type or both types are std::complex.
 * In such cases, the resulting type will be std::complex of the larger type between the arithmetic type and the value
 * type of the std::complex.
 *
 * @tparam T1 First type
 * @tparam T2 Second type
 */
template <typename T1, typename T2>
struct common_type : std::common_type<T1, T2> {};

/**
 * @brief Specialisation of common_type for cases where the first type is arithmetic and the second is std::complex.
 *
 * This results in a std::complex type where the value type is the larger of the arithmetic type and the complex's value
 * type.
 *
 * @tparam T1 Arithmetic type
 * @tparam T2 Value type of the std::complex
 */
template <typename T1, typename T2>
struct common_type<T1, std::complex<T2>> {
  /// @brief The resulting type is std::complex with the common type of T1 and T2.
  using type = std::complex<typename std::common_type_t<T1, T2>>;
};

/**
 * @brief Specialisation of common_type for cases where the first type is std::complex and the second is arithmetic.
 *
 * This results in a std::complex type where the value type is the larger of the complex's value type and the arithmetic
 * type.
 *
 * @tparam T1 Value type of the std::complex
 * @tparam T2 Arithmetic type
 */
template <typename T1, typename T2>
struct common_type<std::complex<T1>, T2> {
  /// @brief The resulting type is std::complex with the common type of T1 and T2.
  using type = std::complex<typename std::common_type_t<T1, T2>>;
};

/**
 * @brief Specialisation of common_type for cases where both types are std::complex.
 *
 * This results in a std::complex type where the value type is the larger of the two underlying complex types.
 *
 * @tparam T1 Value type of the first std::complex
 * @tparam T2 Value type of the second std::complex
 */
template <typename T1, typename T2>
struct common_type<std::complex<T1>, std::complex<T2>> {
  /// @brief The resulting type is std::complex with the common type of T1 and T2.
  using type = std::complex<typename std::common_type_t<T1, T2>>;
};

/**
 * @brief Helper alias template for the common_type structure, similar to std::common_type_t.
 *
 * Provides an alias for the type resulting from the common_type structure.
 *
 * @tparam T1 First type
 * @tparam T2 Second type
 */
template <typename T1, typename T2>
using common_type_t = typename common_type<T1, T2>::type;

/**
 * @brief Concept that ensures the type is a complex number type.
 *
 * This concept checks if the type `T` is a specialization of the `std::complex` template,
 * and the underlying value type (i.e., `T::value_type`) must also satisfy the `ArithmeticType` concept.
 * It ensures that `T` is a complex number with an arithmetic value type.
 *
 * @tparam T The type to check.
 */
template <typename T>
concept complex_type = std::is_same_v<std::decay_t<T>, std::complex<typename T::value_type>> &&
                       std::is_arithmetic_v<typename T::value_type>;

/**
 * @brief Concept that ensures the type is either arithmetic or a complex type.
 *
 * This concept is satisfied if the type `T` is either an arithmetic type
 * (such as `int`, `float`, etc.) or a complex type (i.e., a specialization of `std::complex` with an arithmetic value
 * type). It is used to ensure that operations work with both real numbers and complex numbers.
 *
 * @tparam T The type to check.
 */
template <typename T>
concept vector_type = std::is_arithmetic_v<T> || complex_type<T>;

/**
 * @brief Trait to determine if a type is a std::complex type.
 *
 * This struct is specialized for std::complex types, returning true_type for complex types
 * and false_type for all other types.
 *
 * @tparam T The type to check.
 */
template <typename T>
struct is_complex : std::false_type {};

/**
 * @brief Specialization of is_complex for std::complex types.
 *
 * This specialization returns true_type for any type that is std::complex<T>.
 *
 * @tparam T The underlying type of the complex number.
 */
template <typename T>
struct is_complex<std::complex<T>> : std::true_type {};

/**
 * @brief Helper variable template for is_complex.
 *
 * This variable evaluates to true if T is a std::complex type, otherwise false.
 *
 * @tparam T The type to check.
 */
template <typename T>
inline constexpr bool is_complex_v = is_complex<T>::value;

/**
 * @class vector
 * @brief Represents a mathematical vector in n-dimensional space.
 */
template <vector_type T, std::size_t Length> //
class vector : private std::array<T, Length> {

public:
  using value_type = T;
  using std::array<T, Length>::begin;
  using std::array<T, Length>::end;
  using std::array<T, Length>::cbegin;
  using std::array<T, Length>::cend;
  using std::array<T, Length>::rbegin;
  using std::array<T, Length>::rend;
  using std::array<T, Length>::crbegin;
  using std::array<T, Length>::crend;
  using std::array<T, Length>::empty;
  using std::array<T, Length>::size;
  using std::array<T, Length>::operator[];

  /**
   * @brief Default constructor that initialises all elements of the vector to zero.
   *
   * This constructor initialises the vector by calling the constructor with a value of 0.
   */
  [[nodiscard]] constexpr vector() : std::array<T, Length>() {
    std::fill(begin(), end(), T{});
  }

  /**
   * @brief Constructor that initializes the vector using an initializer list.
   *
   * @param list An initializer list containing the elements to initialize the vector.
   * @throw std::out_of_range if the initializer list size exceeds the vector Length.
   */
  [[nodiscard]] constexpr vector(std::initializer_list<T> const &list) : std::array<T, Length>() {
    if (list.size() > Length) {
      throw std::out_of_range("Initializer list size must match vector Length");
    }
    std::copy(list.begin(), list.end(), begin());
  }

  /**
   * @brief Constructor that initialises all elements of the vector to a given value.
   *
   * This constructor fills the vector with the specified value for all elements.
   * It leverages `std::fill` to ensure that all entries in the array are initialised with `value`.
   *
   * @param value The value used to initialise all elements of the vector.
   */
  [[nodiscard]] constexpr vector(T const value) : std::array<T, Length>() {
    std::fill(begin(), end(), value);
  }

  /**
   * @brief Adds two vectors element-wise and returns the result.
   *
   * This function performs element-wise addition of two vectors and returns a new vector
   * of the result. The result's type is deduced using `std::common_type` to ensure compatibility
   * between different types of vectors.
   *
   * @tparam U The type of elements in the other vector being added.
   * @param other The vector to add to the current vector.
   * @return A new vector containing the element-wise sum of the two vectors.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto add(vector<U, Length> const &other) const {
    vector<common_type_t<T, U>, Length> result;
    std::transform(cbegin(), cend(), other.cbegin(), result.begin(),
                   [](auto const &a, auto const &b) { return common_type_t<T, U>(a) + common_type_t<T, U>(b); });

    return result;
  }

  /**
   * @brief Adds a scalar to each element of the vector and returns the result.
   *
   * This function adds a scalar value to every element in the vector and returns a new vector
   * containing the result. The result's type is determined using `std::common_type` to ensure
   * compatibility between the vector's element type and the scalar type.
   *
   * @tparam U The type of the scalar value being added.
   * @param scalar The scalar value to add to each element of the vector.
   * @return A new vector where each element is the result of adding the scalar to the corresponding element.
   */
  template <typename U>
  [[nodiscard]] constexpr auto add(U const scalar) const {
    vector<common_type_t<T, U>, Length> result;
    std::transform(cbegin(), cend(), result.begin(),
                   [scalar](auto const &a) { return common_type_t<T, U>(a) + common_type_t<T, U>(scalar); });
    return result;
  }

  /**
   * @brief Adds two vectors element-wise using the `+` operator.
   *
   * This operator overload allows element-wise addition of two vectors using the `+` operator.
   * The result is calculated by calling the `add` function.
   *
   * @tparam U The type of elements in the other vector being added.
   * @param other The vector to add to the current vector.
   * @return A new vector containing the element-wise sum of the two vectors.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator+(vector<U, Length> const &other) const {
    return add(other);
  }

  /**
   * @brief Adds a scalar to each element of the vector using the `+` operator.
   *
   * This operator overload adds a scalar to every element of the vector using the `+` operator.
   * The result is calculated by calling the `add` function.
   *
   * @tparam U The type of the scalar value being added.
   * @param scalar The scalar value to add to each element of the vector.
   * @return A new vector where each element is the result of adding the scalar to the corresponding element.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator+(U const scalar) const {
    return add(scalar);
  }

  /**
   * @brief Adds a scalar to a vector.
   *
   * This friend function allows adding a scalar to a vector, returning a new vector
   * with the scalar added to each element of the original vector.
   *
   * @tparam U The type of the scalar.
   * @param scalar The scalar value to add.
   * @param vec The vector to add the scalar to.
   *
   * @return A new vector with the result of the addition.
   */
  template <vector_type U>
  friend constexpr auto operator+(U const scalar, vector<T, Length> const &vec) {
    return vec + scalar;
  }

  /**
   * @brief Performs element-wise addition of two vectors using the `+=` operator.
   *
   * This operator overload allows element-wise addition of two vectors, updating the current vector
   * with the result of the addition.
   *
   * @tparam U The type of elements in the other vector being added.
   * @param other The vector to add to the current vector.
   * @return A reference to the current vector after the addition.
   */
  template <vector_type U>
  constexpr auto &operator+=(vector<U, Length> const &other) {
    std::transform(cbegin(), cend(), other.cbegin(), begin(),
                   [](auto const &a, auto const &b) { return common_type_t<T, U>(a) + common_type_t<T, U>(b); });
    return *this;
  }

  /**
   * @brief Adds a scalar to each element of the vector using the `+=` operator.
   *
   * This operator overload allows a scalar to be added to every element of the vector, updating the current vector
   * with the result of the addition.
   *
   * @tparam U The type of the scalar value being added.
   * @param scalar The scalar value to add to each element of the vector.
   * @return A reference to the current vector after the addition.
   */
  template <vector_type U>
  constexpr auto &operator+=(U const scalar) {
    std::transform(cbegin(), cend(), begin(),
                   [scalar](T const &el) { return common_type_t<T, U>(el) + common_type_t<T, U>(scalar); });
    return *this;
  }

  /**
   * @brief Subtracts another vector from this vector.
   *
   * This function performs element-wise subtraction of another vector from the current vector
   * and returns the result by adding the negative of the other vector.
   *
   * @tparam U The type of elements in the other vector being subtracted.
   * @param other The vector to subtract from the current vector.
   * @return A new vector containing the result of the element-wise subtraction.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto subtract(vector<U, Length> const &other) const {
    return add(-other);
  }

  /**
   * @brief Subtracts a scalar from each element of the vector.
   *
   * This function subtracts a scalar value from every element in the vector and returns a new vector
   * containing the result.
   *
   * @tparam U The type of the scalar value being subtracted.
   * @param scalar The scalar value to subtract from each element of the vector.
   * @return A new vector where each element is the result of subtracting the scalar from the corresponding element.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto subtract(U const scalar) const {
    return add(-scalar);
  }

  /**
   * @brief Subtracts another vector from this vector using the `-` operator.
   *
   * This operator overload allows element-wise subtraction of another vector from the current vector
   * using the `-` operator.
   *
   * @tparam U The type of elements in the other vector being subtracted.
   * @param other The vector to subtract from the current vector.
   * @return A new vector containing the result of the element-wise subtraction.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator-(vector<U, Length> const &other) const {
    return subtract(other);
  }

  /**
   * @brief Subtracts a scalar from each element of the vector using the `-` operator.
   *
   * This operator overload allows a scalar to be subtracted from every element of the vector
   * using the `-` operator.
   *
   * @tparam U The type of the scalar value being subtracted.
   * @param scalar The scalar value to subtract from each element of the vector.
   * @return A new vector where each element is the result of subtracting the scalar from the corresponding element.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator-(U const scalar) const {
    return subtract(scalar);
  }

  /**
   * @brief Subtracts a scalar to a vector.
   *
   * This friend function allows subtracting a scalar to a vector, returning a new vector
   * with the scalar subtracted from each element of the original vector.
   *
   * @tparam U The type of the scalar.
   * @param scalar The scalar value to subtract.
   * @param vec The vector to add the scalar to.
   *
   * @return A new vector with the result of the subtraction.
   */
  template <vector_type U>
  friend constexpr auto operator-(U const scalar, vector<T, Length> const &vec) {
    return vec - scalar;
  }

  /**
   * @brief Performs element-wise subtraction of another vector using the `-=` operator.
   *
   * This operator overload allows element-wise subtraction of another vector from the current vector,
   * updating the current vector with the result.
   *
   * @tparam U The type of elements in the other vector being subtracted.
   * @param other The vector to subtract from the current vector.
   * @return A reference to the current vector after the subtraction.
   */
  template <vector_type U>
  constexpr auto &operator-=(vector<U, Length> const &other) {
    std::transform(cbegin(), cend(), other.cbegin(), begin(),
                   [](auto const &a, auto const &b) { return common_type_t<T, U>(a) - common_type_t<T, U>(b); });
    return *this;
  }

  /**
   * @brief Subtracts a scalar from each element of the vector using the `-=` operator.
   *
   * This operator overload allows a scalar to be subtracted from every element of the vector,
   * updating the current vector with the result.
   *
   * @tparam U The type of the scalar value being subtracted.
   * @param scalar The scalar value to subtract from each element of the vector.
   * @return A reference to the current vector after the subtraction.
   */
  template <vector_type U>
  constexpr auto &operator-=(U const scalar) {
    std::transform(cbegin(), cend(), begin(),
                   [scalar](auto const &el) { return common_type_t<T, U>(el) - common_type_t<T, U>(scalar); });
    return *this;
  }

  /**
   * @brief Calculates the dot product of two vectors.
   *
   * This function computes the dot product of the current vector with another vector.
   * The dot product is the sum of the products of corresponding elements from both vectors.
   * It returns a single scalar value representing the result.
   *
   * The function uses `std::transform_reduce` to efficiently calculate the dot product,
   * applying element-wise multiplication and accumulating the result.
   *
   * @tparam U The type of the elements in the other vector.
   * @param other The vector with which the dot product is computed. This vector must have the same Length as the
   * current vector.
   * @return The scalar result of the dot product, with type `common_type_t<T, U>`.
   *
   * @throws std::invalid_argument if the vectors have different sizes (if this condition is checked elsewhere).
   */
  template <typename U>
  [[nodiscard]] constexpr auto dot(vector<U, Length> const &other) const {
    return std::transform_reduce(
        cbegin(), cend(), other.cbegin(), common_type_t<T, U>(0), std::plus<>(),
        [](auto const &a, auto const &b) { return common_type_t<T, U>(a) * common_type_t<T, U>(b); });
  }

  /**
   * @brief Calculates the cross product of two 3D vectors.
   *
   * This function computes the cross product of the current vector with another vector.
   * It is only valid for 3D vectors, and a static assertion is used to enforce this.
   *
   * @tparam U The type of elements in the other vector.
   * @param other The vector to compute the cross product with.
   * @return A new vector representing the cross product.
   * @throws std::logic_error if the Length of the vector is not 3.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto cross(vector<U, Length> const &other) const {
    static_assert(Length == 3, "Cross product is only allowed for 3D vectors.");
    vector<common_type_t<T, U>, Length> cross;

    cross[0] = (*this)[1] * other[2] - (*this)[2] * other[1];
    cross[1] = (*this)[2] * other[0] - (*this)[0] * other[2];
    cross[2] = (*this)[0] * other[1] - (*this)[1] * other[0];

    return cross;
  }

  /**
   * @brief Scales the vector by a given scalar.
   *
   * This function multiplies each element of the vector by a scalar value and returns
   * a new vector containing the result.
   *
   * @tparam U The type of the scalar value.
   * @param scalar The scalar value to scale the vector by.
   * @return A new vector where each element is scaled by the scalar.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto scale(U const scalar) const {
    vector<common_type_t<T, U>, Length> result;
    std::transform(cbegin(), cend(), result.begin(),
                   [scalar](auto const &el) { return common_type_t<T, U>(el) * common_type_t<T, U>(scalar); });
    return result;
  }

  /**
   * @brief Calculates the dot product using the `*` operator.
   *
   * This operator overload allows the use of the `*` operator to calculate the dot product
   * of two vectors.
   *
   * @tparam U The type of elements in the other vector.
   * @param other The vector to compute the dot product with.
   * @return The dot product as a scalar value.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator*(vector<U, Length> const &other) const {
    return dot(other);
  }

  /**
   * @brief Scales the vector using the `*` operator.
   *
   * This operator overload allows the use of the `*` operator to scale the vector by a scalar value.
   *
   * @tparam U The type of the scalar value.
   * @param scalar The scalar value to scale the vector by.
   * @return A new vector where each element is scaled by the scalar.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator*(U const scalar) const {
    return scale(scalar);
  }

  /**
   * @brief Scales a vector by a scalar.
   *
   * This friend function allows scaling a vector by a scalar, returning a new vector
   * with each element of the original vector multiplied by the scalar.
   *
   * @tparam U The type of the scalar.
   * @param scalar The scalar value to scale by.
   * @param vec The vector to scale.
   *
   * @return A new vector with the result of the scaling.
   */
  template <vector_type U>
  friend constexpr auto operator*(U const scalar, vector<T, Length> const &vec) {
    return vec * scalar;
  }

  /**
   * @brief Scales the vector in place using the `*=` operator.
   *
   * This operator overload allows in-place scaling of the vector by a scalar value.
   *
   * @tparam U The type of the scalar value.
   * @param scalar The scalar value to scale the vector by.
   * @return A reference to the current vector after scaling.
   */
  template <vector_type U>
  constexpr auto &operator*=(U const scalar) {
    std::transform(cbegin(), cend(), begin(),
                   [scalar](auto const &el) { return common_type_t<T, U>(el) * common_type_t<T, U>(scalar); });
    return *this;
  }

  /**
   * @brief Scales the vector by the inverse of a scalar using the `/` operator.
   *
   * This operator overload allows scaling the vector by the reciprocal of a scalar value.
   *
   * @tparam U The type of the scalar value.
   * @param scalar The scalar value to scale the vector by.
   * @return A new vector where each element is scaled by the reciprocal of the scalar.
   */
  template <vector_type U>
  [[nodiscard]] constexpr auto operator/(U const scalar) const {
    return scale(1 / scalar);
  }

  /**
   * @brief Performs inverse scaling of a vector by a scalar.
   *
   * This friend function allows inverse scaling of a vector by a scalar, returning a new vector
   * with each element of the original vector divided by the scalar.
   *
   * @tparam U The type of the scalar.
   * @param scalar The scalar value to inversely scale by.
   * @param vec The vector to scale.
   *
   * @return A new vector with the result of the inverse scaling.
   */
  template <vector_type U>
  friend constexpr auto operator/(U const scalar, vector<T, Length> const &vec) {
    return vec / scalar;
  }

  /**
   * @brief Scales the vector in place using the `/=` operator.
   *
   * This operator overload allows in-place scaling of the vector by the reciprocal of a scalar value.
   *
   * @tparam U The type of the scalar value.
   * @param scalar The scalar value to scale the vector by.
   * @return A reference to the current vector after scaling.
   */
  template <vector_type U>
  constexpr auto &operator/=(U const scalar) {
    std::transform(cbegin(), cend(), begin(),
                   [scalar](T const &el) { return common_type_t<T, U>(el) * (1 / common_type_t<T, U>(scalar)); });
    return *this;
  }

  /**
   * @brief Negates the vector.
   *
   * This function scales the vector by -1, effectively returning the negated vector.
   *
   * @return A new vector representing the negated value of the current vector.
   */
  [[nodiscard]] constexpr auto operator-() const {
    return scale(-1);
  }

  /**
   * @brief Computes the Euclidean magnitude (Length) of the vector.
   *
   * This function calculates the Euclidean magnitude of the vector.
   * For real number vectors, the magnitude is computed as the square root
   * of the dot product of the vector with itself. For complex number vectors,
   * the magnitude is calculated as the square root of the sum of the squared
   * magnitudes of each element (using `std::norm` for the squared modulus).
   *
   * If the vector contains complex numbers, the function uses
   * `std::transform_reduce` to compute the sum of the squared magnitudes
   * of each element. For real numbers, the function uses the `dot` product
   * of the vector with itself and returns the square root of that result.
   *
   * @return The magnitude of the vector as a scalar value.
   */
  [[nodiscard]] constexpr auto norm() const {
    if constexpr (is_complex_v<T>) {
      return std::sqrt(std::transform_reduce(cbegin(), cend(), 0.0, std::plus<>(), [](const auto &val) {
        return std::norm(val); // |val|^2 = val * conj(val)
      }));
    } else {
      return std::sqrt(dot(*this));
    }
  }

  /**
   * @brief Normalizes the vector.
   *
   * This function returns a new vector that is the normalized version of the current vector,
   * which has a magnitude of 1. This is done by scaling the vector by the inverse of its magnitude.
   *
   * @throws std::logic_error when norm is zero. This usually happens when zero vector is passed
   * @return A new vector that is the normalized form of the current vector.
   */
  [[nodiscard]] constexpr auto to_normalized() const {
    auto _norm = norm();
    if (_norm == 0) {
      throw std::logic_error("zero norm results in divide by zero");
    }
    return scale(1 / norm());
  }

  /**
   * @brief Compares two vectors for equality.
   *
   * This function checks if the current vector is equal to another vector by comparing their elements.
   *
   * @param other The vector to compare with.
   * @return `true` if the vectors are equal, otherwise `false`.
   */
  [[nodiscard]] constexpr auto is_equal(vector<T, Length> const &other) const {
    return std::equal(cbegin(), cend(), other.cbegin());
  }

  /**
   * @brief Equality operator for vectors.
   *
   * This operator overload allows the use of the `==` operator to compare two vectors for equality.
   *
   * @param other The vector to compare with.
   * @return `true` if the vectors are equal, otherwise `false`.
   */
  [[nodiscard]] constexpr auto operator==(vector<T, Length> const &other) const {
    return is_equal(other);
  }

  /**
   * @brief Converts the vector elements to a different type, handling complex numbers.
   *
   * If the elements are of type `std::complex`, it multiplies the element by its conjugate and
   * then casts the result to the specified type. For other types, it performs a direct cast.
   *
   * @tparam AsType The type to which the elements will be cast.
   * @return A new vector with elements of the specified type.
   */
  template <vector_type AsType>
  [[nodiscard]] vector<AsType, Length> constexpr const as_type() const {
    vector<AsType, Length> result;

    std::transform(cbegin(), cend(), result.begin(), [](T el) {
      if constexpr (std::is_same_v<T, std::complex<typename T::value_type>>) {
        return static_cast<AsType>(el.real() * el.real() + el.imag() * el.imag());
      } else {
        return static_cast<AsType>(el);
      }
    });

    return result;
  }

  /**
   * @brief Converts the vector to a string representation.
   *
   * This function creates a string representation of the vector in the format "[el1, el2, ..., elN]".
   *
   * @return A string representation of the vector.
   */
  [[nodiscard]] constexpr std::string view(int precision = 20) const {
    bool f_is_first = false;
    std::stringstream ss;

    ss << std::setprecision(precision) << "[";
    if (!empty()) {
      for (auto const &el : *this) {
        if (!f_is_first) {
          ss << el;
          f_is_first = true;
        } else {
          ss << ", " << el;
        }
      }
    }
    ss << "]";

    return ss.str();
  }

  /**
   * @brief Stream insertion operator for vectors.
   *
   * This operator overload allows a vector to be inserted into an output stream,
   * outputting the vector in its string representation format.
   *
   * @param os The output stream.
   * @param other The vector to be output.
   * @return The output stream with the vector representation.
   */
  friend std::ostream &operator<<(std::ostream &os, vector const &other) {
    os << other.view();
    return os;
  }
};

} // namespace firefly
