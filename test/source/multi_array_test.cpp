#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include "gtest/gtest.h"

TEST(multi_array, basic_2D1)
{
  uint64_t width = 5;
  uint64_t height = 5;
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(8192);

  // Test fill
  for (uint64_t i = 0; i < width * height; ++i) {
    EXPECT_EQ(grid.GetValue(i), 8192);
  }
  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Clear the grid.
  grid.clear();
}

TEST(multi_array, basic_3D1)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  std::vector<uint64_t> v = {width, height, depth};
  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(384);

  for (uint64_t i = 0; i < width * height * depth; ++i) {
    EXPECT_EQ(grid.GetValue(i), 384);
  }
  grid.clear();
}

TEST(multi_array, basic_4D1)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t depth2 = 5;
  std::vector<uint64_t> v = {width, height, depth, depth2};
  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(42);

  for (uint64_t i = 0; i < width * height * depth * depth2; ++i) {
    EXPECT_EQ(grid.GetValue(i), 42);
  }
  grid.clear();
}