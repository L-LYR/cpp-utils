#ifndef __CPP_UTILS_MEMORY_POLICY__
#define __CPP_UTILS_MEMORY_POLICY__

#include <cstddef>
#include <new>
#include <tuple>
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
  using SizeType = std::size_t;
  using DifferenceType = std::ptrdiff_t;

public:
  template <typename U> struct rebind { using other = StandardPolicy<U>; };

public:
  StandardPolicy() {}
  ~StandardPolicy() {}
  StandardPolicy(const StandardPolicy &) {}
  template <typename U> StandardPolicy(const StandardPolicy<U> &) {}

  // standard allocation
  Pointer allocate(SizeType n) {
    return reinterpret_cast<Pointer>(::operator new(n * sizeof(ValueType)));
  }
  // standard deallocation
  void deallocate(Pointer p, SizeType n) { ::operator delete(p); }
};

// memory can only be deallocated by the allocator with the same policy
template <typename T, typename U>
inline bool operator==(const StandardPolicy<T> &, const StandardPolicy<U> &) {
  return true;
}

template <typename T, typename OtherPolicy>
inline bool operator==(const StandardPolicy<T> &, const OtherPolicy &) {
  return false;
}

} // namespace memory
} // namespace cpp_utils

#endif