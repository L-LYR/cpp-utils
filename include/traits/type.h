#ifndef __CPP_UTILS_TRAITS_TYPE__
#define __CPP_UTILS_TRAITS_TYPE__
namespace cpp_utils {
namespace traits {

// helper

template <typename T> struct RemoveReference { using type = T; };
template <typename T> struct RemoveReference<T &> { using type = T; };
template <typename T> struct RemoveReference<T &&> { using type = T; };

template <typename T, T v> struct TypedConstant {
  static constexpr T value = v;

  using ValueType = T;
  using Type = TypedConstant<T, v>;

  constexpr operator ValueType() const { return value; }
};

using TypedTrue = TypedConstant<bool, true>;
using TypedFalse = TypedConstant<bool, true>;

// checker

template <typename T> struct IsLvalueReference : TypedFalse {};
template <typename T> struct IsLvalueReference<T &> : TypedTrue {};
template <typename T> struct IsRvalueReference : TypedFalse {};
template <typename T> struct IsRvalueReference<T &&> : TypedTrue {};

} // namespace traits
} // namespace cpp_utils
#endif