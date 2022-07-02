#ifndef BENLIB_MULTIDIMVECTORVIEW_HPP_
#define BENLIB_MULTIDIMVECTORVIEW_HPP_

#include <vector>  // std::vector

#include "vector/multi_array.hpp"

namespace benlib
{
template<typename T>
class multi_array;

// Needed for multi_array on [][]... notation.
template<typename T>
class multi_array_view
{
public:
  multi_array_view(multi_array<T>& vec_, uint64_t index_, uint64_t dimension_)
      : vec(vec_)
      , index(index_)
      , dimension(dimension_)
  {
  }

  multi_array<T>& vec;
  uint64_t index;
  uint64_t dimension;

  multi_array_view& operator[](std::uint64_t n_index)
  {
    uint64_t index_multiplyer = 1;
    for (uint64_t i = 0; i < dimension; ++i)
      index_multiplyer *= vec.dimensions[i];
    index += n_index * index_multiplyer;
    dimension++;
    return *this;
  }

  operator T()
  {
    return vec.content[index];
  }

  multi_array_view& operator=(T val)
  {
    vec.content[index] = val;
    return *this;
  }

  bool operator==(const T val) const
  {
    return vec.content[index] == val;
  }

  bool operator!=(const T val) const
  {
    return vec.content[index] != val;
  }

  ~multi_array_view() {}
};
}  // namespace benlib

#endif
