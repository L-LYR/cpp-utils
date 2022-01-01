#ifndef __CPP_UTILS_TRAITS_IS_CONSTRUCTIBLE__
#define __CPP_UTILS_TRAITS_IS_CONSTRUCTIBLE__

#include "traits/bool_utils.hpp"
#include "traits/declval.hpp"
#include "traits/result_type.hpp"

namespace cpp_utils {
namespace traits {
namespace details {

template <typename T, typename... Args,
          typename = decltype(T(declval<Args>()...))>
auto IsConstructibleImplChecker(int) -> Ok;

template <typename T, typename...> auto IsConstructibleImplChecker(...) -> Err;

} // namespace details

template <typename T, typename... Args>
struct IsConstructible
    : TypedBoolConstant<sizeof(details::IsConstructibleImplChecker<T, Args...>(
                            0)) == sizeof(Ok)> {
  // TODO: static_assert(is_complete_or_unbounded)
};

template <typename T, typename... Args>
struct IsNotConstructible : NOT<IsConstructible<T, Args...>> {};

} // namespace traits
} // namespace cpp_utils

#endif