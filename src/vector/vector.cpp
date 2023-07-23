
#include "firefly/vector.hpp"

namespace Firefly {

Vector::Vector(std::size_t _size)
    : m_vec{std::make_shared<VectorType>(_size)} {}

Vector::Vector(VectorType const &_vec)
    : m_vec(std::make_shared<VectorType>(_vec)) {}

Vector::Vector(Vector const &_fvec)
    : m_vec(std::make_shared<VectorType>(*_fvec.m_vec)) {}

} // namespace Firefly
