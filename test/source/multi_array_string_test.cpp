#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include "gtest/gtest.h"

TEST(multi_array, basic_1D_string)
{
  std::vector<uint64_t> v = {3};
  auto grid = benlib::multi_array<std::string>(v);
  grid.fill("");
  grid.set_value(0, "a");
  grid.set_value(1, "b");
  grid.set_value(2, "c");
  EXPECT_EQ(grid.get_value(0), "a");
  EXPECT_EQ(grid.get_value(1), "b");
  EXPECT_EQ(grid.get_value(2), "c");
}

TEST(multi_array, basic_2D_string)
{
  std::vector<uint64_t> v = {3, 3};
  auto grid = benlib::multi_array<std::string>(v);
  grid.fill("");
  grid.set_value(0, "a");
  grid.set_value(1, "b");
  grid.set_value(2, "c");
  EXPECT_EQ(grid.get_value(0), "a");
  EXPECT_EQ(grid.get_value(1), "b");
  EXPECT_EQ(grid.get_value(2), "c");
}