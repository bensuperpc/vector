#ifndef BENLIB_VECTOR_HPP_
#define BENLIB_VECTOR_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdint>  // uint8_t, uint64_t
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <vector>  // std::vector

namespace benlib
{
template<typename T, bool mersenne_64 = true>
void random(std::vector<T> vect, const T& fMin, const T& fMax)
{
  typedef typename std::conditional<mersenne_64 == true,
                                    std::mt19937_64,
                                    std::mt19937>::type random_engine;
  std::random_device rnd_device;
  random_engine rng;
  rng.seed(rnd_device());

  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(fMin, fMax);
    auto gen = [&dist, &rng]() { return dist(rng); };
    std::generate(vect.begin(), vect.end(), gen);

  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(fMin, fMax);
    auto gen = [&dist, &rng]() { return dist(rng); };
    std::generate(vect.begin(), vect.end(), gen);

  } else if (std::is_same<T, std::string>::value) {
    std::uniform_int_distribution<uint8_t> dist(fMin, fMax);
    auto gen = [&dist, &rng]() { return static_cast<char>(dist(rng)); };
    std::generate(vect.begin(), vect.end(), gen);
  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
  }
}
template<typename T>
T multmultiplies(const std::vector<T>& vec)
{
  return std::reduce(vec.begin(), vec.end(), 1, std::multiplies<T>());
}

}  // namespace benlib
#endif  // BENLIB_VECTOR_HPP_
