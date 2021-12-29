#include "traits/strong_type.hpp"
#include "traits/traits.hpp"
#include "gtest/gtest.h"

using namespace cpp_utils::traits;

TEST(strong_type, definition) {
  struct IntegerWith32Bits {};
  using i32 = StrongType<int32_t, IntegerWith32Bits, PreIncremental>;

  i32 i(32);
  ASSERT_EQ(i.actual().get(), 32);
  ++i;
  ASSERT_EQ(i.actual().get(), 33);
}
auto main(int argc, char **argv) -> int {

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}