#ifndef __CPP_UTILS_TRAITS_MOVE__
#define __CPP_UTILS_TRAITS_MOVE__

#include "traits/type.h"
namespace cpp_utils {
namespace traits {

// move forward an lvalue
template <typename T>
constexpr T &&forward(typename RemoveReference<T>::type &t) {
  return static_cast<T &&>(t);
};

// move forward an rvalue
template <typename T>
constexpr T &&forward(typename RemoveReference<T>::type &&t) {
  static_assert(!IsLvalueReference<T>::value,
                "template argument T must be lvalue reference");
  return static_cast<T &&>(t);
}

} // namespace traits
} // namespace cpp_utils
#endif