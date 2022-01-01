#ifndef __CPP_UTILS_TRAITS_TYPED_CONSTANT__
#define __CPP_UTILS_TRAITS_TYPED_CONSTANT__

namespace cpp_utils {
namespace traits {

// Typed Constant
template <typename T, T v> struct TypedConstant {
  static constexpr T value = v;

  using ValueType = T;
  using Type = TypedConstant<T, v>;

  constexpr operator ValueType() const { return value; }
};

// void type
template <typename...> using VoidType = void;

} // namespace traits
} // namespace cpp_utils

#endif