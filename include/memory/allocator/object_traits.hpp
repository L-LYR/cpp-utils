#ifndef __CPP_UTILS_MEMORY_OBJECT_TRAITS__
#define __CPP_UTILS_MEMORY_OBJECT_TRAITS__

#include "traits/move.h"

namespace cpp_utils {
namespace memory {

template <typename T> class ObjectTraits {
public:
  template <typename U> struct rebind { using other = ObjectTraits<U>; };

public:
  ObjectTraits() {}
  ~ObjectTraits() {}
  template <typename U> ObjectTraits(const ObjectTraits<U> &) {}

  T *address(T &r) { return &r; }
  const T *address(const T &r) { return &r; }

  template <typename U, typename... Args>
  void construct_at(U *p, Args &&...args) {
    ::new (p) U(cpp_utils::traits::forward<Args>(args)...);
  }

  void construct_at(T *p, const T &r) { ::new (p) T(r); }

  void destroy_at(T *p) { p->~T(); }
};

} // namespace memory
} // namespace cpp_utils

#endif