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

TEST(multi_array, basic_3D_string)
{
  std::vector<uint64_t> v = {3, 3, 3};
  auto grid = benlib::multi_array<std::string>(v);
  grid.fill("");
  grid.set_value(0, "a");
  grid.set_value(1, "b");
  grid.set_value(2, "c");
  EXPECT_EQ(grid.get_value(0), "a");
  EXPECT_EQ(grid.get_value(1), "b");
  EXPECT_EQ(grid.get_value(2), "c");
}

TEST(multi_array, basic_1D_uint8_t)
{
  std::vector<uint64_t> v = {3};
  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_2D_uint8_t)
{
  std::vector<uint64_t> v = {3, 3};
  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_3D_uint8_t)
{
  std::vector<uint64_t> v = {3, 3, 3};
  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_1D_uint16_t)
{
  std::vector<uint64_t> v = {3};
  auto grid = benlib::multi_array<uint16_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_2D_uint16_t)
{
  std::vector<uint64_t> v = {3, 3};
  auto grid = benlib::multi_array<uint16_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_3D_uint16_t)
{
  std::vector<uint64_t> v = {3, 3, 3};
  auto grid = benlib::multi_array<uint16_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_1D_uint32_t)
{
  std::vector<uint64_t> v = {3};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_2D_uint32_t)
{
  std::vector<uint64_t> v = {3, 3};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_3D_uint32_t)
{
  std::vector<uint64_t> v = {3, 3, 3};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_1D_uint64_t)
{
  std::vector<uint64_t> v = {3};
  auto grid = benlib::multi_array<uint64_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_2D_uint64_t)
{
  std::vector<uint64_t> v = {3, 3};
  auto grid = benlib::multi_array<uint64_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}

TEST(multi_array, basic_3D_uint64_t)
{
  std::vector<uint64_t> v = {3, 3, 3};
  auto grid = benlib::multi_array<uint64_t>(v);
  grid.fill(0);
  grid.set_value(0, 1);
  grid.set_value(1, 2);
  grid.set_value(2, 3);
  EXPECT_EQ(grid.get_value(0), 1);
  EXPECT_EQ(grid.get_value(1), 2);
  EXPECT_EQ(grid.get_value(2), 3);
}
