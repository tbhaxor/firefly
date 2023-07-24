#include <functional>
#include <numeric>

#include "firefly/vector.hpp"

namespace Firefly {

Real Vector::ElemSum() const {
  return std::reduce(m_vec.cbegin(), m_vec.cend(), 0x0, std::plus<Real>());
}
} // namespace Firefly