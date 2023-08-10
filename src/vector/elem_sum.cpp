#include <numeric>

#include "firefly/vector.hpp"

namespace Firefly {

Real Vector::ElemSum() const {
  return std::accumulate(m_vec.cbegin(), m_vec.cend(), static_cast<Real>(0));
}
} // namespace Firefly