#include "memory/allocator/allocator.hpp"
#include "gtest/gtest.h"

struct StructForTestAllocator {
  char c;
  short s;
  int i;
  long l;
  long long ll;
  float f;
  double d;
  long double ld;
};

template <typename T, typename Allocator = cpp_utils::memory::Allocator<T>>
class List {
private:
  template <typename U> struct ListNode {
    U elem;
    ListNode<U> *next = nullptr;
  };

  using NodeAllocator = typename Allocator::template rebind<ListNode<T>>::other;
  template <typename U> struct ListImpl : public NodeAllocator {
    ListNode<U> *header = nullptr;
    int len = 0;
  };

public: // for simple test
  ListImpl<T> impl;

public:
  List<T>(int n) {
    assert(n > 0);
    impl.len = n;
    impl.header = impl.allocate(1);
    impl.construct_at(impl.header);
    for (size_t i = 0; i < n - 1; i++) {
      auto p = impl.allocate(1);
      impl.construct_at(p);
      p->next = impl.header->next;
      impl.header = p;
    }
  }
  ~List<T>() { impl.deallocate(impl.header, impl.len); }
};

TEST(basic_allocation, test_allocator) {
  {
    cpp_utils::memory::Allocator<int> default_int_allocator;
    auto one_int_ptr = default_int_allocator.allocate(1);
    ASSERT_NE(one_int_ptr, nullptr);
    *one_int_ptr = 100;
    ASSERT_EQ(*one_int_ptr, 100);
    default_int_allocator.deallocate(one_int_ptr, 1);
  }
  {
    cpp_utils::memory::Allocator<StructForTestAllocator>
        default_struct_allocator;
    auto test_struct_array = default_struct_allocator.allocate(10);
    ASSERT_NE(test_struct_array, nullptr);
    default_struct_allocator.deallocate(test_struct_array, 10);
  }
}

TEST(rebind, test_allocator) { List<int> list(10); }

auto main(int argc, char **argv) -> int {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}