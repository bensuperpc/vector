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

#ifndef BENLIB_VECTOR_HPP_
#define BENLIB_VECTOR_HPP_

#include <algorithm>  // std::move, std::copy, std::fill
#include <cstdint>  // uint8_t, uint64_t
#include <iostream>  // std::cout, std::endl
#include <random>  // std::mt19937, std::uniform_int_distribution
#include <string>  // std::string
#include <vector>  // std::vector

namespace benlib
{

template<typename T>
constexpr T accumulate(const std::vector<T>& vec)
{
  return std::accumulate(vec.begin(), vec.end(), 0);
}

template<typename T>
constexpr T multiplies(const std::vector<T>& vec)
{
  return std::reduce(vec.begin(), vec.end(), 1, std::multiplies<T>());
}

template<typename T>
constexpr std::vector<T> multiplies(const std::vector<T>& vec, const std::vector<T>& vec2)
{
  std::vector<T> result(vec.size());
  std::transform(vec.begin(), vec.end(), vec2.begin(), result.begin(), std::multiplies<T>());
  return result;
}

template<typename T>
constexpr std::vector<T> sum(const std::vector<T>& vec, const std::vector<T>& vec2)
{
  std::vector<T> result(vec.size());
  std::transform(vec.begin(), vec.end(), vec2.begin(), result.begin(), std::plus<T>());
  return result;
}

template<typename T>
void print(const std::vector<T>& vec)
{
  for (const auto& v : vec) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

template<typename T>
void print(const std::vector<std::vector<T>>& vec)
{
  for (const auto& v : vec) {
    print(v);
  }
}

template<typename T>
constexpr std::vector<T> convert_2D_to_1D(const std::vector<std::vector<T>>& vec)
{
  std::vector<T> result(vec.size() * vec[0].size());
  for (typename std::vector<T>::size_type i = 0; i < vec.size(); ++i) {
    std::copy(vec[i].begin(), vec[i].end(), result.begin() + i * vec[0].size());
  }
  return result;
}

template<typename T>
constexpr std::vector<T> convert_3D_to_1D(const std::vector<std::vector<std::vector<T>>>& vec)
{
  std::vector<T> result(vec.size() * vec[0].size() * vec[0][0].size());
  for (typename std::vector<T>::size_type i = 0; i < vec.size(); ++i) {
    for (typename std::vector<T>::size_type j = 0; j < vec[0].size(); ++j) {
      std::copy(vec[i][j].begin(), vec[i][j].end(), result.begin() + i * vec[0].size() + j * vec[0][0].size());
    }
  }
  return result;
}

/*
template<typename T>
constexpr auto plus = sum<T>;
*/

}  // namespace benlib
#endif  // BENLIB_VECTOR_HPP_