#ifndef __CPP_UTILS_TRAITS_UTILS__
#define __CPP_UTILS_TRAITS_UTILS__

#include "traits/typed_constant.hpp"

namespace cpp_utils {
namespace traits {

// Bool Constant
template <bool V> using TypedBoolConstant = TypedConstant<bool, V>;
using TypedTrue = TypedBoolConstant<true>;
using TypedFalse = TypedBoolConstant<false>;

// Logical Operator
template <bool Condition, typename TrueBranch, typename FalseBranch>
struct IF { // condition is true
  using Result = TrueBranch;
};

template <typename TrueBranch, typename FalseBranch>
struct IF<false, TrueBranch, FalseBranch> { // condition is false
  using Result = FalseBranch;
};

// OR
template <typename...> struct OR; // base

template <> struct OR<> : public TypedFalse {}; // empty

template <typename B1> struct OR<B1> : public B1 {}; // one

template <typename B1, typename B2> // two
struct OR<B1, B2> : public IF<B1::value, B1, B2>::Result {};

template <typename B1, typename B2, typename B3, typename... Bn>
struct OR<B1, B2, B3, Bn...> // more
    : public IF<B1::value, B1, OR<B2, B3, Bn...>>::Result {};

// AND
template <typename...> struct AND; // base

template <> struct AND<> : public TypedTrue {}; // empty

template <typename B1> struct AND<B1> : public B1 {}; // one

template <typename B1, typename B2> // two
struct AND<B1, B2> : public IF<B1::value, B2, B1>::Result {};

template <typename B1, typename B2, typename B3, typename... Bn>
struct AND<B1, B2, B3, Bn...> // more
    : public IF<B1::value, AND<B2, B3, Bn...>, B1>::Result {};

// NOT
template <typename B> struct NOT : public TypedBoolConstant<!bool(B::value)> {};

} // namespace traits
} // namespace cpp_utils

#endif