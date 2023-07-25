#include "firefly/vector.hpp"

namespace Firefly {

std::size_t Vector::Size() const { return m_vec.size(); }

std::size_t Vector::Rank() const { return this->Size(); }

} // namespace Firefly