#pragma once

#include <cstddef>
#include <memory>
#include <ostream>
#include <vector>

#ifdef DOUBLE_PRECISION
using Real = double;
#else
using Real = float;
#endif

namespace Firefly {
using VectorType = std::vector<Real>;

class Vector {
  std::shared_ptr<VectorType> m_vec;

public:
  Vector(Vector &&) = delete;
  Vector() = delete;

  Vector(std::size_t size);
  Vector(VectorType const &_vec);
  Vector(Vector const &_f);

  [[nodiscard]] std::string View() const;
  friend std::ostream &operator<<(std::ostream &os, Vector const &_fvec);

  [[nodiscard]] Real At(std::size_t idx) const;
  [[nodiscard]] Real &At(std::size_t idx);

  [[nodiscard]] Real operator[](std::size_t idx) const;
  [[nodiscard]] Real &operator[](std::size_t idx);

  [[nodiscard]] std::size_t Size() const;
  [[nodiscard]] std::size_t Rank() const;

  [[nodiscard]] std::unique_ptr<Vector> Add(Vector const &_fvec) const;
  [[nodiscard]] std::unique_ptr<Vector> Add(Real const &_scalar) const;
  [[nodiscard]] std::unique_ptr<Vector> operator+(Vector const &_fvec) const;
  [[nodiscard]] std::unique_ptr<Vector> operator+(Real const &_scalar) const;
  [[nodiscard]] std::unique_ptr<Vector> operator++() const;

  [[nodiscard]] std::unique_ptr<Vector> Scale(Real const &_fvec) const;
  [[nodiscard]] std::unique_ptr<Vector> operator*(Real const &_scalar) const;

  [[nodiscard]] std::unique_ptr<Vector> Subtract(Vector const &_fvec) const;
  [[nodiscard]] std::unique_ptr<Vector> Subtract(Real const &_scalar) const;
  [[nodiscard]] std::unique_ptr<Vector> operator-(Vector const &_fvec) const;
  [[nodiscard]] std::unique_ptr<Vector> operator-(Real const &_scalar) const;
  [[nodiscard]] std::unique_ptr<Vector> operator--() const;

  [[nodiscard]] Real Dot(Vector const &_fvec) const;

  [[nodiscard]] std::unique_ptr<Vector> Cross(Vector const &_fvec) const;

  [[nodiscard]] Real ElemSum() const;

  [[nodiscard]] Real Magnitude() const;

  [[nodiscard]] std::unique_ptr<Vector> Normalize() const;

  [[nodiscard]] Real AngleWith(Vector const &_fvec) const;

  [[nodiscard]] bool IsZero();
  [[nodiscard]] bool IsNormalized();
  [[nodiscard]] bool IsParallel(Vector const &_fvec);
  [[nodiscard]] bool IsOrthogonal(Vector const &_fvec);

  [[nodiscard]] Real ParallelogramArea(Vector const &_fvec) const;
  [[nodiscard]] Real TriangleArea(Vector const &_fvec) const;
};

} // namespace Firefly