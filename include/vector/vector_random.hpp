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

#ifndef BENLIB_VECTOR_RANDOM_HPP_
#define BENLIB_VECTOR_RANDOM_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdint>  // uint8_t, uint64_t
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <vector>  // std::vector

namespace benlib
{

/*
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

  } else {
    // throw std::runtime_error("Benlib::random: Unsupported type.");
  }
}
*/

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect, const T& min, const T& max, R& rng)
{
  using dist_type = typename std::conditional<std::is_integral<T>::value,
                                              std::uniform_int_distribution<T>,
                                              std::uniform_real_distribution<T> >::type;

  thread_local static dist_type dist;

  for (auto& elem : vect) {
    elem = dist(rng, typename dist_type::param_type {min, max});
  }
}

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect, const T& min, const T& max)
{
  thread_local static R rng(std::random_device {}());

  using dist_type = typename std::conditional<std::is_integral<T>::value,
                                              std::uniform_int_distribution<T>,
                                              std::uniform_real_distribution<T> >::type;

  thread_local static dist_type dist;

  for (auto& elem : vect) {
    elem = dist(rng, typename dist_type::param_type {min, max});
  }
}

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect, const T& min, const T& max, const uint64_t& seed)
{
  thread_local static R rng(static_cast<typename T::result_type>(seed));
  random<T, R>(vect, min, max, rng);
}

template<typename T, typename R = std::mt19937_64>
void random(std::vector<T>& vect)
{
  const auto min = std::numeric_limits<T>::min();
  const auto max = std::numeric_limits<T>::max();

  random(vect, min, max);
}

}  // namespace benlib
#endif  // BENLIB_VECTOR_RANDOM_HPP_
