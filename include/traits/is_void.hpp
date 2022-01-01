#ifndef __CPP_UTILS_TRAITS_IS_VOID__
#define __CPP_UTILS_TRAITS_IS_VOID__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <typename T> struct IsVoid : public TypedFalse {};

template <> struct IsVoid<void> : public TypedTrue {};
template <> struct IsVoid<const void> : public TypedTrue {};
template <> struct IsVoid<volatile void> : public TypedTrue {};
template <> struct IsVoid<const volatile void> : public TypedTrue {};

template <typename T> struct IsNotVoid : public NOT<IsVoid<T>> {};

} // namespace traits
} // namespace cpp_utils

#endif