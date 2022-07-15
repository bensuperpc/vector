#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include "gtest/gtest.h"

TEST(multi_array, advanced_1D_uint8_t)
{
  uint64_t width = 5;
  uint64_t gridsize = width;
  std::vector<uint64_t> v = {width};

  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test set value
  grid.set_value(0, 42);
  EXPECT_EQ(grid.get_value(0), 42);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = benlib::multi_array<uint8_t>(grid);
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i] = 42;
    EXPECT_EQ(grid[i], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_1D_uint32_t)
{
  uint64_t width = 5;
  uint64_t gridsize = width;
  std::vector<uint64_t> v = {width};

  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test set value
  grid.set_value(0, 42);
  EXPECT_EQ(grid.get_value(0), 42);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i] = 42;
    EXPECT_EQ(grid[i], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_2D_uint8_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t gridsize = width * height;

  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test set value
  grid.set_value(0, 42);
  EXPECT_EQ(grid.get_value(0), 42);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0] = 42;
    EXPECT_EQ(grid[i][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_2D_uint32_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t gridsize = width * height;

  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test set value
  grid.set_value(0, 42);
  EXPECT_EQ(grid.get_value(0), 42);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0] = 42;
    EXPECT_EQ(grid[i][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_3D_uint8_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t gridsize = width * height * depth;
  std::vector<uint64_t> v = {width, height, depth};

  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0] = 42;
    EXPECT_EQ(grid[i][0][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_3D_uint32_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t gridsize = width * height * depth;
  std::vector<uint64_t> v = {width, height, depth};

  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0] = 42;
    EXPECT_EQ(grid[i][0][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_4D_uint8_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t fourth = 5;
  uint64_t gridsize = width * height * depth * fourth;
  std::vector<uint64_t> v = {width, height, depth, fourth};

  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_4D_uint32_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t fourth = 5;
  uint64_t gridsize = width * height * depth * fourth;
  std::vector<uint64_t> v = {width, height, depth, fourth};

  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_5D_uint8_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t fourth = 5;
  uint64_t fifth = 5;
  uint64_t gridsize = width * height * depth * fourth * fifth;
  std::vector<uint64_t> v = {width, height, depth, fourth, fifth};

  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, advanced_5D_uint32_t)
{
  uint64_t width = 5;
  uint64_t height = 5;
  uint64_t depth = 5;
  uint64_t fourth = 5;
  uint64_t fifth = 5;
  uint64_t gridsize = width * height * depth * fourth * fifth;
  std::vector<uint64_t> v = {width, height, depth, fourth, fifth};

  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.get_value(i), 96);
  }

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test Resize
  grid.resize(v);

  // Test Size
  EXPECT_EQ(grid.size(), gridsize);

  // Test the = operator.
  auto grid2 = grid;
  EXPECT_EQ(grid, grid2);

  // Test GetDimensions
  EXPECT_EQ(grid.GetDim(), v);

  // Test the == operator.
  grid2.fill(0);
  grid.fill(0);
  EXPECT_EQ(grid == grid2, true);

  // Test is_equal
  EXPECT_EQ(grid.is_equal(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the + operator.
  grid.fill(2);
  grid2.fill(2);

  auto grid3 = grid + grid2;
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid3.get_value(i), 4);
  }

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0][0], 42);
  }

  // Test the get_value() function.
  EXPECT_EQ(grid.get_value(0), 42);

  // Test the set_value() function.
  grid.set_value(1, 71);
  EXPECT_EQ(grid.get_value(1), 71);

  // Test the get_grid() function.
  auto grid_copy = grid.get_grid();

  // Test the set_grid() function.
  grid.set_grid(grid_copy);
  EXPECT_EQ(grid.get_grid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}

TEST(multi_array, random_1D_uint32_t)
{
  uint64_t width = 5;
  std::vector<uint64_t> v = {width};

  auto grid = benlib::multi_array<uint32_t>(v);
  grid.random(0, 100);
  EXPECT_TRUE((grid[0] > 0) && (grid[0] <= 100));
}
