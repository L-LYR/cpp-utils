#ifndef __CPP_UTILS_TRAITS_IS_CONSTRUCTIBLE__
#define __CPP_UTILS_TRAITS_IS_CONSTRUCTIBLE__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {
namespace details {

template <typename T, typename... Args> auto IsConstructibleImpl() -> bool {
  // TODO: Impl it!
  return false;
}
} // namespace details

template <typename T, typename... Args>
struct IsConstructible
    : TypedBoolConstant<details::IsConstructibleImpl<T, Args...>()> {
  // TODO: static_assert(is_complete_or_unbounded)
};

} // namespace traits
} // namespace cpp_utils

#endif