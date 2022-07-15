//////////////////////////////////////////////////////////////
//   ____                                                   //
//  | __ )  ___ _ __  ___ _   _ _ __   ___ _ __ _ __   ___  //
//  |  _ \ / _ \ '_ \/ __| | | | '_ \ / _ \ '__| '_ \ / __| //
//  | |_) |  __/ | | \__ \ |_| | |_) |  __/ |  | |_) | (__  //
//  |____/ \___|_| |_|___/\__,_| .__/ \___|_|  | .__/ \___| //
//                             |_|             |_|          //
//////////////////////////////////////////////////////////////
//                                                          //
//  Vector, 2022                                            //
//  Created: 01, July, 2022                                 //
//  Modified: 09, July, 2022                                //
//                                                          //
//  License: MIT                                            //
//  Source:                                                 //
//  OS: ALL                                                 //
//  CPU: ALL                                                //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef BENLIB_RANDOM_HPP_
#define BENLIB_RANDOM_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdint>  // uint8_t, uint64_t
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <string>  // std::string

namespace benlib
{

template<typename T, typename R = std::mt19937_64>
T random(const T& min, const T& max)
{
  R rng {std::random_device {}()};
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);

  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
    return T {};
  }
}

template<typename T, typename R = std::mt19937_64>
T random(const T& min, const T& max, R& rng)
{
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);

  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
    return T {};
  }
}

template<typename T, typename R = std::mt19937_64>
T random()
{
  constexpr auto min = std::numeric_limits<T>::min();
  constexpr auto max = std::numeric_limits<T>::max();

  R rng {std::random_device {}()};
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);
  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
    return T {};
  }
}

template<typename T, typename R = std::mt19937_64>
T random(R& rng)
{
  constexpr auto min = std::numeric_limits<T>::min();
  constexpr auto max = std::numeric_limits<T>::max();

  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);
  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
    return T {};
  }
}

}  // namespace benlib
#endif  // BENLIB_VECTOR_RANDOM_HPP_
