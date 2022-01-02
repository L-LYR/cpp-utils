#ifndef __CPP_UTILS_TRAITS_IS_CONSTRUCTIBLE__
#define __CPP_UTILS_TRAITS_IS_CONSTRUCTIBLE__

#include "traits/bool_utils.hpp"
#include "traits/declval.hpp"
#include "traits/is_complete.hpp"
#include "traits/is_destructible.hpp"
#include "traits/result_type.hpp"

namespace cpp_utils {
namespace traits {
namespace details {

// regular case
template <typename T, typename... Args,
          typename = decltype(T(declval<Args>()...))>
auto IsConstructibleRegularChecker(int) -> Ok;
template <typename, typename...> auto IsConstructibleRegularChecker(...) -> Err;
template <typename T, typename... Args>
struct IsConstructibleRegularImpl
    : public IsOk<decltype(IsConstructibleRegularChecker<T, Args...>(0))> {};
// reference
template <typename T> auto IsConstructibleRefChecker(T) -> Ok;
template <typename T> auto IsConstructibleRefChecker(...) -> Err;
template <typename T, typename U>
struct IsConstructibleRefImpl : public TypedFalse {};
template <typename LRef, typename U>
struct IsConstructibleRefImpl<LRef &, U>
    : public IsOk<decltype(IsConstructibleRefChecker<LRef &>(declval<U>()))> {};
template <typename RRef, typename U>
struct IsConstructibleRefImpl<RRef &&, U>
    : public IsOk<decltype(IsConstructibleRefChecker<RRef &&>(declval<U>()))> {
};
// conversion
template <typename T, typename U, typename = decltype(::new T(declval<U>()))>
auto IsConstructibleConvChecker(int) -> Ok;
template <typename, typename> auto IsConstructibleConvChecker(...) -> Err;
template <typename T, typename U>
struct IsConstructibleConvImpl
    : public AND<IsDestructible<T>,
                 IsOk<decltype(IsConstructibleConvChecker<T, U>(0))>> {};

} // namespace details

template <typename T, typename... Args>
struct IsConstructible
    : public details::IsConstructibleRegularImpl<T, Args...> {
  static_assert(IsComplete<T>::value, "Target type is imcomplete");
};

template <typename T, typename U>
struct IsConstructible<T, U> : public details::IsConstructibleConvImpl<T, U> {};

template <typename LRef, typename U>
struct IsConstructible<LRef &, U>
    : public details::IsConstructibleRefImpl<LRef &, U> {};

template <typename RRef, typename U>
struct IsConstructible<RRef &&, U>
    : public details::IsConstructibleRefImpl<RRef &&, U> {};

template <> struct IsConstructible<void> : public TypedFalse {};
template <> struct IsConstructible<void const> : public TypedFalse {};
template <> struct IsConstructible<void volatile> : public TypedFalse {};
template <> struct IsConstructible<void const volatile> : public TypedFalse {};

template <typename T, typename... Args>
struct IsNotConstructible : NOT<IsConstructible<T, Args...>> {};

} // namespace traits
} // namespace cpp_utils

#endif