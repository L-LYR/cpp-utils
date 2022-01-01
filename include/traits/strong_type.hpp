#ifndef __CPP_UTILS_TRAITS_STRONG__
#define __CPP_UTILS_TRAITS_STRONG__

#include "traits/is_reference.hpp"
#include "traits/move.hpp"

namespace cpp_utils {
namespace traits {

template <typename NormalType, typename Parameter,
          template <typename> class... Attributes>
struct StrongType
    : public Attributes<StrongType<NormalType, Parameter, Attributes...>>... {
  // ctor
  StrongType() = default; // default

  explicit constexpr StrongType(const NormalType &value)
      : value(value) { // copy
    // TODO: static_assert(IsCopyConstructible)
  }

  template <typename T = NormalType, typename = IsNotReference<T>>
  explicit constexpr StrongType(T &&value) : value(move(value)) {
    // TODO: static_assert(IsMoveConstructible)
  }

  // get TODO: change the name
  constexpr auto get() -> NormalType & { return value; }
  constexpr auto get() const -> const
      typename RemoveReference<NormalType>::type & {
    return value;
  };

  // ref
  using Reference = StrongType<NormalType &, Parameter, Attributes...>;
  operator Reference() { return value; }

  // TODO: support strong function type

private:
  NormalType value;
};

template <template <typename T> class Strong, typename T>
constexpr auto make_strong(const T &value) -> Strong<T> {
  return Strong<T>(value);
}

} // namespace traits
} // namespace cpp_utils

#endif