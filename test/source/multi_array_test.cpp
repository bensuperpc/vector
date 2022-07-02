#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include "gtest/gtest.h"

TEST(multi_array, advanced_1D_uint8_t)
{
  uint64_t width = 5;
  uint64_t gridsize = width;
  std::vector<uint64_t> v = {width};

  auto grid = benlib::MultiVector<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
  }

  // Test set value
  grid.SetValue(0, 42);
  EXPECT_EQ(grid.GetValue(0), 42);

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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i] = 42;
    EXPECT_EQ(grid[i], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
  }

  // Test set value
  grid.SetValue(0, 42);
  EXPECT_EQ(grid.GetValue(0), 42);

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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i] = 42;
    EXPECT_EQ(grid[i], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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
  auto grid = benlib::MultiVector<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
  }

  // Test set value
  grid.SetValue(0, 42);
  EXPECT_EQ(grid.GetValue(0), 42);

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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0] = 42;
    EXPECT_EQ(grid[i][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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
  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
  }

  // Test set value
  grid.SetValue(0, 42);
  EXPECT_EQ(grid.GetValue(0), 42);

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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0] = 42;
    EXPECT_EQ(grid[i][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0] = 42;
    EXPECT_EQ(grid[i][0][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0] = 42;
    EXPECT_EQ(grid[i][0][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint8_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

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

  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(96);

  // Test fill
  for (uint64_t i = 0; i < gridsize; ++i) {
    EXPECT_EQ(grid.GetValue(i), 96);
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

  // Test IsEqual
  EXPECT_EQ(grid.IsEqual(grid2), true);

  // Test the != operator.
  grid.fill(1);
  EXPECT_EQ(grid != grid2, true);

  // Test the [] operator.
  for (uint64_t i = 0; i < width; ++i) {
    grid[i][0][0][0][0] = 42;
    EXPECT_EQ(grid[i][0][0][0][0], 42);
  }

  // Test the GetValue() function.
  EXPECT_EQ(grid.GetValue(0), 42);

  // Test the SetValue() function.
  grid.SetValue(1, 71);
  EXPECT_EQ(grid.GetValue(1), 71);

  // Test the GetGrid() function.
  auto grid_copy = grid.GetGrid();

  // Test the SetGrid() function.
  grid.SetGrid(grid_copy);
  EXPECT_EQ(grid.GetGrid(), grid_copy);

  // Clear the grid.
  grid.clear();
  EXPECT_EQ(grid.size(), 0);
  grid.shrink_to_fit();
}
