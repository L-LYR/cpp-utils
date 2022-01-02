#ifndef __CPP_UTILS_TRAITS_MEMBER_TYPE_OF__
#define __CPP_UTILS_TRAITS_MEMBER_TYPE_OF__

namespace cpp_utils {
namespace traits {

template <typename> struct MemberTypeOf {};
template <typename T, typename U> struct MemberTypeOf<U T::*> {
  using type = U;
};

} // namespace traits
} // namespace cpp_utils

#endif