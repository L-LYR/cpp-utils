#ifndef __CPP_UTILS_TRAITS_TYPE_UTILS__
#define __CPP_UTILS_TRAITS_TYPE_UTILS__

#include "traits/bool_utils.hpp"
#include "traits/type_traits_impl.hpp"
#include "traits/typed_constant.hpp"

namespace cpp_utils {
namespace traits {

// helper

template <typename T> struct RemoveReference { using type = T; };
template <typename T> struct RemoveReference<T &> { using type = T; };
template <typename T> struct RemoveReference<T &&> { using type = T; };

// checker

template <typename T> struct IsLvalueReference : TypedFalse {};
template <typename T> struct IsLvalueReference<T &> : TypedTrue {};
template <typename T> struct IsRvalueReference : TypedFalse {};
template <typename T> struct IsRvalueReference<T &&> : TypedTrue {};
template <typename T>
struct IsReference : OR<IsLvalueReference<T>, IsRvalueReference<T>>::Result {};
template <typename T> struct IsNotReference : NOT<IsReference<T>> {};

template <typename T, typename = void>
struct IsReferenceable : public TypedFalse {};
template <typename T>
struct IsReferenceable<T, VoidType<T &>> : public TypedTrue {};

template <typename T, typename... Args>
struct IsConstructible
    : TypedBoolConstant<details::IsConstructibleImpl<T, Args...>()> {
  // TODO: static_assert(is_complete_or_unbounded)
};

template <typename T, bool = IsReferenceable<T>::value>
struct isCopyConstructibleImpl;
template <typename T>
struct isCopyConstructibleImpl<T, false> : public TypedFalse {};
template <typename T>
struct isCopyConstructibleImpl<T, true> : public IsConstructible<T, const T &> {
};

template <typename T>
struct IsCopyConstructible : public isCopyConstructibleImpl<T> {
  // TODO: static_assert(is_complete_or_unbounded)
};

// controller

template <bool Condition, typename T = void> struct EnableIf {};
template <typename T> struct EnableIf<true, T> { using type = T; }; // enable

} // namespace traits
} // namespace cpp_utils

#endif