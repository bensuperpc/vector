#include <cstdint>  // uint32_t, uint64_t
#include <memory>  // std::unique_ptr (std::make_unique)
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include "gtest/gtest.h"

TEST(multi_array, smart_ptr_1D_string)
{
  std::vector<uint64_t> v = {3};
  auto gridA = benlib::multi_array<std::unique_ptr<std::string>>(v);
  auto gridB = benlib::multi_array<std::unique_ptr<std::string>>(v);
  EXPECT_EQ(gridA.size(), 3);
  EXPECT_EQ(gridB.size(), 3);
}
