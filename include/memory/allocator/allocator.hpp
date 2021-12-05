#ifndef __CPP_UTILS_MEMORY_ALLOCATOR__
#define __CPP_UTILS_MEMORY_ALLOCATOR__

#include "object_traits.hpp"
#include "standard_policy.hpp"

namespace cpp_utils {
namespace memory {

template <typename T, typename Policy = StandardPolicy<T>,
          typename ObjectTraits = ObjectTraits<T>>
class Allocator : public Policy, public ObjectTraits {
public:
  using ValueType = typename Policy::ValueType;
  using SizeType = typename Policy::SizeType;
  using DifferenceType = typename Policy::DifferenceType;
  using Pointer = typename Policy::Pointer;
  using ConstPointer = typename Policy::ConstPointer;
  using Reference = typename Policy::Reference;
  using ConstReference = typename Policy::ConstReference;

public:
  template <typename U> struct rebind {
    using other = Allocator<U, typename Policy::template rebind<U>::other,
                            typename ObjectTraits::template rebind<U>::other>;
  };

public:
  Allocator() {}
  ~Allocator() {}

  template <typename U> Allocator(const Allocator<U> &) {}
  Allocator(const Allocator &rhs) : ObjectTraits(rhs), Policy(rhs) {}

  template <typename U, typename OtherPolicy, typename OtherObjectTraits>
  inline Allocator(Allocator<U, OtherPolicy, OtherObjectTraits> const &rhs)
      : ObjectTraits(rhs), Policy(rhs) {}
};

// memory can only be deallocated by the allocator with the same policy
template <typename LT, typename LP, typename LO, typename RT, typename RP,
          typename RO>
inline auto operator==(const Allocator<LT, LP, LO> &lhs,
                       const Allocator<RT, RP, RO> &rhs) -> bool {
  return operator==(dynamic_cast<const LP &>(lhs),
                    dynamic_cast<const RP &>(rhs));
}
template <typename LT, typename LP, typename LO, typename RT, typename RP,
          typename RO>
inline auto operator!=(const Allocator<LT, LP, LO> &lhs,
                       const Allocator<RT, RP, RO> &rhs) -> bool {
  return !operator==(lhs, rhs);
}

template <typename T, typename P, typename O, typename OtherAllocator>
inline auto operator==(const Allocator<T, P, O> &lhs, const OtherAllocator &rhs)
    -> bool {
  return operator==(dynamic_cast<P &>(lhs), rhs);
}
template <typename T, typename P, typename O, typename OtherAllocator>
inline auto operator!=(const Allocator<T, P, O> &lhs, const OtherAllocator &rhs)
    -> bool {
  return !operator==(lhs, rhs);
}

template <typename T, typename P, typename O>
inline auto operator==(const Allocator<T, P, O> &lhs,
                       const Allocator<T, P, O> &rhs) -> bool {
  return operator==(dynamic_cast<const P &>(lhs), dynamic_cast<const P &>(rhs));
}
template <typename T, typename P, typename O>
inline auto operator!=(const Allocator<T, P, O> &lhs,
                       const Allocator<T, P, O> &rhs) -> bool {
  return !operator==(lhs, rhs);
}

} // namespace memory
} // namespace cpp_utils

#endif