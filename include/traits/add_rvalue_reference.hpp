#ifndef __CPP_UTILS_TRAITS_ADD_RVALUE_REFERENCE__
#define __CPP_UTILS_TRAITS_ADD_RVALUE_REFERENCE__

#include "traits/bool_utils.hpp"
#include "traits/is_reference.hpp"
#include "traits/is_void.hpp"

namespace cpp_utils {
namespace traits {
namespace details {

template <typename T, bool B> struct AddRvalueReferenceResult {
  using Result = T;
};
template <typename T> struct AddRvalueReferenceResult<T, true> {
  using Result = T &&;
};

template <typename T> struct AddRvalueReferenceImpl {
  // NOTE: Here we cannot use IF, because IF need both results to be valid.
  // For 'void' type, the result 'void &&' is invalid.
  using type = typename AddRvalueReferenceResult<
      T, AND<IsNotVoid<T>, IsNotReference<T>>::value>::Result;
};

} // namespace details

template <typename T> struct AddRvalueReference {
  using type = typename details::AddRvalueReferenceImpl<T>::type;
};

} // namespace traits
} // namespace cpp_utils

#endif