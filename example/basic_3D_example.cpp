#include <iostream>
#include <vector>

#include "vector/multi_array.hpp"

int main()
{
  // Set dimensions, 3D array with 5x5x5 elements
  std::vector<uint64_t> vecDim = {5, 5, 5};
  auto vec3D_A = benlib::multi_array<uint32_t>(vecDim);

  // fill with 1
  vec3D_A.fill(1);

  // print
  std::cout << "Must be equal to 1: " << vec3D_A[0][0][0] << std::endl;

  // set value
  vec3D_A[1][1][1] = 2;

  // get value (Faster than using [] operator)
  std::vector<uint64_t> vecCoor = {1, 1, 1};
  std::cout << "Must be equal to 2: " << vec3D_A.get_value(vecCoor) << std::endl;

  // set value (Faster than using [] operator)
  vec3D_A.set_value(vecCoor, 3);
  std::cout << "Must be equal to 3: " << vec3D_A.get_value(vecCoor) << std::endl;
  return 0;
}