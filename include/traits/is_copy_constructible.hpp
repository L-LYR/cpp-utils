#ifndef __CPP_UTILS_TRAITS_IS_COPY_CONSTRUCTIBLE__
#define __CPP_UTILS_TRAITS_IS_COPY_CONSTRUCTIBLE__

#include "traits/is_constructible.hpp"
#include "traits/is_referencable.hpp"

namespace cpp_utils {
namespace traits {

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

} // namespace traits
} // namespace cpp_utils

#endif