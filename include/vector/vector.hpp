#ifndef BENLIB_VECTOR_HPP_
#define BENLIB_VECTOR_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdint>  // uint8_t, uint64_t
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <string>  // std::string
#include <vector>  // std::vector

namespace benlib
{

template<typename T>
constexpr T multiplies(const std::vector<T>& vec)
{
  return std::reduce(vec.begin(), vec.end(), 1, std::multiplies<T>());
}

}  // namespace benlib
#endif  // BENLIB_VECTOR_HPP_
