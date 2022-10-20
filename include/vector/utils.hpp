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

#ifndef BENLIB_COMMON_HPP_
#define BENLIB_COMMON_HPP_

#include <cstddef>  // std::size_t

/*
constexpr uint64_t KB = 1024u;
constexpr uint64_t MB = 1024u * 1024u;
constexpr uint64_t GB = 1024u * 1024u * 1024u;
*/

constexpr std::size_t operator""_KB(const unsigned long long v)
{
  return 1024u * v;
}

constexpr std::size_t operator""_MB(const unsigned long long v)
{
  return 1024u * 1024u * v;
}

constexpr std::size_t operator""_GB(const unsigned long long v)
{
  return 1024u * 1024u * 1024u * v;
}

namespace benlib
{
}  // namespace benlib
#endif  // BENLIB_COMMON_HPP_