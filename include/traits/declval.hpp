#ifndef __CPP_UTILS_TRAITS_DECLVAL__
#define __CPP_UTILS_TRAITS_DECLVAL__

#include "traits/add_rvalue_reference.hpp"

namespace cpp_utils {
namespace traits {

template <typename T> auto declval() -> typename AddRvalueReference<T>::type;

}
} // namespace cpp_utils

#endif