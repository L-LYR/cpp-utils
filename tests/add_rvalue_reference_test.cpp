#include "traits/add_rvalue_reference.hpp"
#include "traits/is_same.hpp"
#include "gtest/gtest.h"

TEST(test_add_rvalue_reference, basic_test) {
  using namespace cpp_utils::traits;
  AddRvalueReference<int>::type i = 3;
  int j = 4;
  ASSERT_EQ(typeid(i), typeid(j));
}

TEST(test_add_rvalue_reference, void_type) {
  using namespace cpp_utils::traits;
  static_assert(IsSame<AddRvalueReference<void>::type, void>::value, "!");
}

auto main(int argc, char **argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}