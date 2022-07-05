#ifndef BENLIB_VECTOR_RANDOM_HPP_
#define BENLIB_VECTOR_RANDOM_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdint>  // uint8_t, uint64_t
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <string>  // std::string
#include <vector>  // std::vector

namespace benlib
{

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect, const T& min, const T& max, R& rng)
{
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    auto gen = [&dist, &rng]() { return dist(rng); };
    std::generate(vect.begin(), vect.end(), gen);

  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(min, max);
    auto gen = [&dist, &rng]() { return dist(rng); };
    std::generate(vect.begin(), vect.end(), gen);

  } else if (std::is_same<T, std::string>::value) {
    std::uniform_int_distribution<uint8_t> dist(min, max);
    auto gen = [&dist, &rng]() { return static_cast<std::string::value_type>(dist(rng)); };
    std::generate(vect.begin(), vect.end(), gen);
  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
  }
}

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect, const T& min, const T& max)
{
  std::random_device rnd_device;
  R rng;
  rng.seed(rnd_device());

  random<T, R>(vect, min, max, rng);
}

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect)
{
  constexpr auto min = std::numeric_limits<T>::min();
  constexpr auto max = std::numeric_limits<T>::max();

  std::random_device rnd_device;
  R rng;
  rng.seed(rnd_device());

  random<T, R>(vect, min, max, rng);
}

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect, const T& min, const T& max, const uint64_t& seed)
{
  R rng(static_cast<typename T::result_type>(seed));
  random<T, R>(vect, min, max, rng);
}

}  // namespace benlib
#endif  // BENLIB_VECTOR_RANDOM_HPP_
