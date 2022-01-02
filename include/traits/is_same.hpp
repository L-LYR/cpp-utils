#ifndef __CPP_UTILS_TRAITS_IS_SAME__
#define __CPP_UTILS_TRAITS_IS_SAME__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <typename T, typename U> struct IsSame : public TypedFalse {};
template <typename T> struct IsSame<T, T> : public TypedTrue {};

} // namespace traits
} // namespace cpp_utils

#endif