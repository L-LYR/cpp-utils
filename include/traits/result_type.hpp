#ifndef __CPP_UTILS_TRAITS_RESULT_TYPE__
#define __CPP_UTILS_TRAITS_RESULT_TYPE__

#include "config/def.hpp"

namespace cpp_utils {
namespace traits {

template <config::size_t N> struct ResultType { char _[N]; };

using Ok = ResultType<1>;
using Err = ResultType<2>;

} // namespace traits
} // namespace cpp_utils

#endif