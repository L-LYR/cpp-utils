#ifndef __CPP_UTILS_TRAITS_IS_FUNCTION__
#define __CPP_UTILS_TRAITS_IS_FUNCTION__

#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

// default
template <typename> struct IsFunction : TypedFalse {};

// regular
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...)> : TypedTrue {};

// variadic
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...)> : TypedTrue {};

// const & volatile
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) const> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) volatile> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) const volatile> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) const> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) volatile> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) const volatile> : TypedTrue {};

// has reference
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) const &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) volatile &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) const volatile &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) const &&> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) volatile &&> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args...) const volatile &&> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) const &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) volatile &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) const volatile &> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) const &&> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) volatile &&> : TypedTrue {};
template <typename ReturnType, typename... Args>
struct IsFunction<ReturnType(Args..., ...) const volatile &&> : TypedTrue {};

} // namespace traits
} // namespace cpp_utils

#endif