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
//  Source: https://stackoverflow.com/a/35687575/10152334   //
//          https://www.fluentcpp.com/2017/10/27/function-aliases-cpp/ //
//  OS: ALL                                                 //
//  CPU: ALL                                                //
//                                                          //
//////////////////////////////////////////////////////////////

#ifndef BENLIB_RANDOM_HPP_
#define BENLIB_RANDOM_HPP_

#include <cstdint>  // uint8_t, uint64_t
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <type_traits>

namespace benlib
{

template<typename T, typename G = std::mt19937_64>
T random(const T& min, const T& max)
{
  thread_local static G rng(std::random_device {}());

  using dist_type = typename std::conditional<std::is_integral<T>::value,
                                              std::uniform_int_distribution<T>,
                                              std::uniform_real_distribution<T> >::type;

  thread_local static dist_type dist;

  return dist(rng, typename dist_type::param_type {min, max});
}

template<typename T, typename G = std::mt19937_64>
T random_v1(const T& min, const T& max)
{
  G rng {std::random_device {}()};
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);
  } else {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  }
}

template<typename T, typename G = std::mt19937_64>
T random(const T& min, const T& max, G& rng)
{
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);

  } else {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  }
}

template<typename T, typename G = std::mt19937_64>
T random()
{
  constexpr auto min = std::numeric_limits<T>::min();
  constexpr auto max = std::numeric_limits<T>::max();

  thread_local static G gen(std::random_device {}());

  using dist_type = typename std::conditional<std::is_integral<T>::value,
                                              std::uniform_int_distribution<T>,
                                              std::uniform_real_distribution<T> >::type;

  thread_local static dist_type dist;

  return dist(gen, typename dist_type::param_type {min, max});
}

template<typename T, typename G = std::mt19937_64>
T random(G& rng)
{
  constexpr auto min = std::numeric_limits<T>::min();
  constexpr auto max = std::numeric_limits<T>::max();

  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(min, max);
    return dist(rng);
  } else {
    std::uniform_real_distribution<T> dist(min, max);
    return dist(rng);
  }
}

template<typename T, typename G = std::mt19937_64>
T random_v2(const T& min, const T& max)
{
  return random<T, G>(min, max);
}

template<typename T, typename G = std::mt19937_64>
T random_v2(G& rng)
{
  return random<T, G>(rng);
}

template<typename T, typename G = std::mt19937_64>
T random_v2()
{
  return random<T, G>();
}

/*
template<typename T, typename G = std::mt19937_64>
constexpr auto random_v2 = random<T, G>;

template<typename T, typename G = std::mt19937_64>
constexpr T (*random_v2)(const T& min, const T& max) = &random<T, G>;


template<typename T, typename G = std::mt19937_64>
constexpr auto& random_v1 = random<T, G>;
*/

}  // namespace benlib
#endif  // BENLIB_VECTOR_RANDOM_HPP_
