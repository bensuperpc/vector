# vector

High performance vectors and multidimensional vectors in **C++17**, with **optional OpenMP acceleration** and **no external dependencies** (Except for testing).

[![stability-experimental](https://img.shields.io/badge/stability-experimental-orange.svg)](https://github.com/mkenney/software-guides/blob/master/STABILITY-BADGES.md#experimental) ![GitHub](https://img.shields.io/github/license/bensuperpc/vector)

## Examples

The number of dimension is almost infinite (1 to 18 446 744 073 709 551 615).

### 2D example

```cpp
#include <iostream>
#include <vector>

#include "vector/multi_array.hpp"

int main()
{
  // Set dimensions, 2D array with 5x5 elements
  std::vector<uint64_t> vecDim = {5, 5};
  auto vec2D_A = benlib::multi_array<uint32_t>(vecDim);

  // fill with 1
  vec2D_A.fill(1);

  // print
  std::cout << "Must be equal to 1: " << vec2D_A[0][0] << std::endl;

  // set value
  vec2D_A[1][1] = 2;

  // get value (Faster than using [] operator)
  std::vector<uint64_t> vecCoor = {1, 1};
  std::cout << "Must be equal to 2: " << vec2D_A.get_value(vecCoor) << std::endl;

  // set value (Faster than using [] operator)
  vec2D_A.set_value(vecCoor, 3);
  std::cout << "Must be equal to 3: " << vec2D_A.get_value(vecCoor) << std::endl;
  return 0;
}
```

### 3D example

```cpp
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
```

## Building and installing

See the [BUILDING](BUILDING.md) document.

## Contributing

See the [CONTRIBUTING](CONTRIBUTING.md) document.

## Licensing

See the [LICENSE](LICENSE) document.
