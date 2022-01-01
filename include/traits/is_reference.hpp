#ifndef __CPP_UTILS_TRAITS_IS_REFERENCE__
#define __CPP_UTILS_TRAITS_IS_REFERENCE__

#include "traits/bool_utils.hpp"
#include "traits/is_lvalue_reference.hpp"
#include "traits/is_rvalue_reference.hpp"

namespace cpp_utils {
namespace traits {

template <typename T>
struct IsReference : OR<IsLvalueReference<T>, IsRvalueReference<T>> {};

template <typename T> struct IsNotReference : NOT<IsReference<T>> {};

} // namespace traits
} // namespace cpp_utils

#endif