#ifndef __CPP_UTILS_MEMORY_POLICY__
#define __CPP_UTILS_MEMORY_POLICY__

#include "config/def.hpp"

namespace cpp_utils {
namespace memory {

/*
  Standard Policy:
    Users should take the opportunity and responsibility to
    allocate and deallocate the memory they need. It just
    help them to call new() and delete() with the unified
    function.
*/

template <typename T> class StandardPolicy {
public:
  using ValueType = T;
  using Pointer = T *;
  using ConstPointer = const T *;
  using Reference = T &;
  using ConstReference = const T &;
  using SizeType = cpp_utils::config::size_t;
  using DifferenceType = cpp_utils::config::ptrdiff_t;

public:
  template <typename U> struct rebind { using other = StandardPolicy<U>; };

public:
  StandardPolicy() {}
  ~StandardPolicy() {}
  StandardPolicy(const StandardPolicy &) {}
  template <typename U> StandardPolicy(const StandardPolicy<U> &) {}

  // standard allocation
  auto allocate(SizeType n) -> Pointer {
    return reinterpret_cast<Pointer>(::operator new(n * sizeof(ValueType)));
  }
  // standard deallocation
  auto deallocate(Pointer p, SizeType n) { ::operator delete(p); }
};

// memory can only be deallocated by the allocator with the same policy
template <typename T, typename U>
inline auto operator==(const StandardPolicy<T> &, const StandardPolicy<U> &)
    -> bool {
  return true;
}

template <typename T, typename OtherPolicy>
inline auto operator==(const StandardPolicy<T> &, const OtherPolicy &) -> bool {
  return false;
}

} // namespace memory
} // namespace cpp_utils

#endif