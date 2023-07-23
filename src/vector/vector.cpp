
#include "firefly/vector.hpp"

namespace Firefly {

Vector::Vector(std::size_t size) : m_vec{std::make_shared<VectorType>(size)} {}

Vector::Vector(VectorType const &_vec)
    : m_vec(std::make_shared<VectorType>(_vec)) {}

Vector::Vector(Vector const &_f)
    : m_vec(std::make_shared<VectorType>(*_f.m_vec)) {}

} // namespace Firefly
