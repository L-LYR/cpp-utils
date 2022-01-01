#ifndef __CPP_UTILS_TRAITS_TYPE_UTILS__
#define __CPP_UTILS_TRAITS_TYPE_UTILS__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <typename T> struct RemoveReference { using type = T; };
template <typename T> struct RemoveReference<T &> { using type = T; };
template <typename T> struct RemoveReference<T &&> { using type = T; };

} // namespace traits
} // namespace cpp_utils

#endif