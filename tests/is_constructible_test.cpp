#include "traits/is_constructible.hpp"
#include "gtest/gtest.h"

struct UndefStruct;

struct TestStruct {
  int i;
  float f;

  TestStruct(int i, float f) : i(i), f(f) {}
  TestStruct(UndefStruct &us);
};

struct Y {
  ~Y() = delete;
};

struct Z {
  ~Z() = default;
};

struct X : Y {};

TEST(test_is_constructible, basic_types) {
  using namespace cpp_utils::traits;
  static_assert(IsConstructible<int, long>::value, "!");
  static_assert(IsConstructible<int, int &&>::value, "!");
  static_assert(IsConstructible<TestStruct, int, float>::value, "!");
  static_assert(IsConstructible<TestStruct, float, int>::value, "!");
  static_assert(IsConstructible<TestStruct, UndefStruct &>::value, "!");
  // static_assert(IsConstructible<UndefStruct>::value, "!");
  static_assert(IsConstructible<Z, Z>::value, "!");
  static_assert(!IsConstructible<TestStruct, char *>::value, "!");
  static_assert(IsConstructible<int &&, float>::value, "!");
  static_assert(!IsConstructible<int &, float>::value, "!");
  static_assert(!IsConstructible<X, Y>::value, "!");
  static_assert(!IsConstructible<Y, X>::value, "!");
  static_assert(!IsConstructible<char[4], char[]>::value, "!");
}

auto main(int argc, char **argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}