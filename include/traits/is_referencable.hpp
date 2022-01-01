#ifndef __CPP_UTILS_TRAITS_IS_REFERENCABLE__
#define __CPP_UTILS_TRAITS_IS_REFERENCABLE__

#include "bool_utils.hpp"

namespace cpp_utils {
namespace traits {

template <typename T, typename = void>
struct IsReferenceable : public TypedFalse {};
template <typename T>
struct IsReferenceable<T, VoidType<T &>> : public TypedTrue {};

} // namespace traits
} // namespace cpp_utils

#endif