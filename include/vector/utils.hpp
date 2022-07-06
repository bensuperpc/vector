#ifndef BENLIB_COMMON_HPP_
#define BENLIB_COMMON_HPP_

#include <cstddef>  // std::size_t

constexpr std::size_t operator""_KB(unsigned long long v)
{
  return 1024u * v;
}

constexpr std::size_t operator""_MB(unsigned long long v)
{
  return 1024u * 1024u * v;
}

constexpr std::size_t operator""_GB(unsigned long long v)
{
  return 1024u * 1024u * 1024u * v;
}

namespace benlib
{
}  // namespace benlib
#endif  // BENLIB_COMMON_HPP_