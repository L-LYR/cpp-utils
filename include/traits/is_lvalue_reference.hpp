#ifndef __CPP_UTILS_TRAITS_IS_LVALUE_REFERENCE__
#define __CPP_UTILS_TRAITS_IS_LVALUE_REFERENCE__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <typename T> struct IsLvalueReference : TypedFalse {};
template <typename T> struct IsLvalueReference<T &> : TypedTrue {};

} // namespace traits
} // namespace cpp_utils

#endif