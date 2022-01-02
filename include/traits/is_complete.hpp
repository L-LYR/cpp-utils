#ifndef __CPP_UTILS_TRAITS_IS_COMPLETE__
#define __CPP_UTILS_TRAITS_IS_COMPLETE__

#include "traits/bool_utils.hpp"
#include "traits/declval.hpp"
#include "traits/is_function.hpp"
#include "traits/is_void.hpp"
#include "traits/remove_reference.hpp"
#include "traits/result_type.hpp"

namespace cpp_utils {
namespace traits {
namespace details {

template <typename T, typename = decltype(sizeof(declval<T>()))>
auto IsCompleteImplChecker(int) -> Ok;
template <typename T> auto IsCompleteImplChecker(...) -> Err;

template <typename T>
struct IsCompleteImpl : IsOk<decltype(IsCompleteImplChecker<T>(0))> {};

} // namespace details

template <typename T>
struct IsComplete : TypedBoolConstant<OR<IsFunction<RemoveReference<T>>,
                                         details::IsCompleteImpl<T>>::value> {};

static_assert(IsComplete<int &>::value, "!");

} // namespace traits
} // namespace cpp_utils

#endif