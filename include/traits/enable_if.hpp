#ifndef __CPP_UTILS_TRAITS_ENABLE_IF__
#define __CPP_UTILS_TRAITS_ENABLE_IF__

namespace cpp_utils {
namespace traits {

template <bool Condition, typename T = void> struct EnableIf {};
template <typename T> struct EnableIf<true, T> { using type = T; };

} // namespace traits
} // namespace cpp_utils

#endif