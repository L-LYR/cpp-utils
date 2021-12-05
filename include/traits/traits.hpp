#ifndef __CPP_UTILS_TRAITS__
#define __CPP_UTILS_TRAITS__

namespace cpp_utils {
namespace traits {

// CRTP base
template <typename T, template <typename> class F> struct CRTP {
  constexpr T &actual() { return static_cast<T &>(*this); }
  constexpr T const &actual() const { return static_cast<T &>(*this); }
};

// Traits
template <typename T> struct PreIncremental : public CRTP<T, PreIncremental> {
  T &operator++() {
    ++this->actual().get();
    return this->actual();
  }
};

} // namespace traits
} // namespace cpp_utils

#endif