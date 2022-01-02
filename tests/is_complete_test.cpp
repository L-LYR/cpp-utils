#include "traits/is_complete.hpp"
#include "gtest/gtest.h"

TEST(test_is_complete, reference_type) {
  using namespace cpp_utils::traits;
  static_assert(IsComplete<int &>::value, "!");
  static_assert(!IsComplete<void>::value, "!");
}
auto main(int argc, char **argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}