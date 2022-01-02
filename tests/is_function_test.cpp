#include "traits/is_function.hpp"
#include "traits/member_type_of.hpp"
#include "gtest/gtest.h"
#include <cstdio>

TEST(test_is_function, basic_test) {
  using namespace cpp_utils::traits;

  int add(int, int);
  static_assert(IsFunction<decltype(add)>::value, "!");

  void echo();
  static_assert(IsFunction<decltype(echo)>::value, "!");

  struct TestStruct {
    int i;
    int const_get(int) const;
    int volatile_set(int) volatile;
  };

  static_assert(
      IsFunction<MemberTypeOf<decltype(&TestStruct::const_get)>::type>::value,
      "!");
  static_assert(
      IsFunction<
          MemberTypeOf<decltype(&TestStruct::volatile_set)>::type>::value,
      "!");
}

TEST(test_is_function, lambda) {
  using namespace cpp_utils::traits;
  auto a = [](void) -> int { return 0; };
  static_assert(!IsFunction<decltype(a)>::value, "!");
}

auto main(int argc, char **argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}