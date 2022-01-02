#ifndef __CPP_UTILS_TRAITS_RESULT_TYPE__
#define __CPP_UTILS_TRAITS_RESULT_TYPE__

#include "config/def.hpp"
#include "traits/bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <config::size_t N> struct ResultType { char _[N]; };

using Ok = ResultType<1>;
using Err = ResultType<2>;

template <typename T>
struct IsOk : TypedBoolConstant<sizeof(T) == sizeof(Ok)> {};

template <typename T>
struct IsErr : TypedBoolConstant<sizeof(T) == sizeof(Err)> {};

} // namespace traits
} // namespace cpp_utils

#endif