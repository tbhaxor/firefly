
#include "firefly/vector.hpp"

namespace Firefly {

Vector::Vector(std::size_t _size) : m_vec(_size) {}

Vector::Vector(VectorType const &_vec) : m_vec(_vec) {}

Vector::Vector(Vector const &_fvec) : m_vec(_fvec.m_vec) {}

} // namespace Firefly
