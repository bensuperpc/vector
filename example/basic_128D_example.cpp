#include <iostream>
#include <vector>

#include "vector/multi_array.hpp"

int main()
{
  // Set dimensions, 128D array with 5x5... elements
  std::vector<uint64_t>&& vecDim = std::vector<uint64_t>(128, 5);
  auto&& vec128D_A = benlib::multi_array<uint32_t>(vecDim);

  // fill with 1
  vec128D_A.fill(1);

  std::vector<uint64_t>&& vecCoor = std::vector<uint64_t>(128, 0);

  // print
  std::cout << "Must be equal to 1: " << vec128D_A.get_value(vecCoor) << std::endl;

  // set value
  vec128D_A.set_value(vecCoor, 3);
  std::cout << "Must be equal to 3: " << vec128D_A.get_value(vecCoor) << std::endl;
  return 0;
}