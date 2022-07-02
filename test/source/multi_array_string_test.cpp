#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include "gtest/gtest.h"

TEST(multi_array, basic_1D_string)
{
  std::vector<uint64_t> v = {3};
  auto grid = benlib::MultiVector<std::string>(v);
  grid.fill("");
  grid.SetValue(0, "a");
  grid.SetValue(1, "b");
  grid.SetValue(2, "c");
  EXPECT_EQ(grid.GetValue(0), "a");
  EXPECT_EQ(grid.GetValue(1), "b");
  EXPECT_EQ(grid.GetValue(2), "c");
}

TEST(multi_array, basic_2D_string)
{
  std::vector<uint64_t> v = {3, 3};
  auto grid = benlib::MultiVector<std::string>(v);
  grid.fill("");
  grid.SetValue(0, "a");
  grid.SetValue(1, "b");
  grid.SetValue(2, "c");
  EXPECT_EQ(grid.GetValue(0), "a");
  EXPECT_EQ(grid.GetValue(1), "b");
  EXPECT_EQ(grid.GetValue(2), "c");
}