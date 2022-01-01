#ifndef __CPP_UTILS_TRAITS_MOVE__
#define __CPP_UTILS_TRAITS_MOVE__

#include "traits/is_lvalue_reference.hpp"
#include "traits/remove_reference.hpp"

namespace cpp_utils {
namespace traits {

// move as an rvalue reference
template <class T>
constexpr auto move(T &&t) -> typename RemoveReference<T>::type && {
  return static_cast<typename RemoveReference<T>::type &&>(t);
}

// move forward an lvalue as an rvalue reference
template <typename T>
constexpr auto forward(typename RemoveReference<T>::type &t) -> T && {
  return static_cast<T &&>(t);
};

// move forward an rvalue
template <typename T>
constexpr auto forward(typename RemoveReference<T>::type &&t) -> T && {
  static_assert(!IsLvalueReference<T>::value,
                "template argument T must be lvalue reference");
  return static_cast<T &&>(t);
}

} // namespace traits
} // namespace cpp_utils

#endif