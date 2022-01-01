#include "traits/is_constructible.hpp"
#include "gtest/gtest.h"

struct TestStruct {
  int i;
  float f;

  TestStruct(int i, float f) : i(i), f(f) {}
};

TEST(test_is_constructible, basic_types) {
  using namespace cpp_utils::traits;
  static_assert(IsConstructible<int, long>::value, "?");

  static_assert(IsConstructible<int, int &&>::value, "?");

  static_assert(IsConstructible<TestStruct, int, float>::value, "?");

  static_assert(IsConstructible<TestStruct, float, int>::value,
                "?"); // I don't know why

  static_assert(IsNotConstructible<TestStruct, char *>::value, "?");
}

auto main(int argc, char **argv) -> int {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}