#ifndef __CPP_UTILS_TRAITS_IS_DESTRUCTIBLE_
#define __CPP_UTILS_TRAITS_IS_DESTRUCTIBLE_

#include "traits/declval.hpp"
#include "traits/result_type.hpp"

namespace cpp_utils {
namespace traits {
namespace details {

template <typename T, typename = decltype(declval<T &>().~T())>
auto IsDestructibleChecker(int) -> Ok;
template <typename> auto IsDestructibleChecker(...) -> Err;
template <typename T>
struct IsDestructibleImpl : IsOk<decltype(IsDestructibleChecker<T>(0))> {};

} // namespace details

template <typename T> struct IsDestructible : details::IsDestructibleImpl<T> {};

} // namespace traits
} // namespace cpp_utils

#endif