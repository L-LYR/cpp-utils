#ifndef __CPP_UTILS_TRAITS_IS_RVALUE_REFERENCE__
#define __CPP_UTILS_TRAITS_IS_RVALUE_REFERENCE__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <typename T> struct IsRvalueReference : TypedFalse {};
template <typename T> struct IsRvalueReference<T &&> : TypedTrue {};

} // namespace traits
} // namespace cpp_utils

#endif