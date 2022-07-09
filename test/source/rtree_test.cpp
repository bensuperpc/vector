#include <cstdint>  // uint32_t, uint64_t
#include <string>  // std::string
#include <vector>  // std::vector

#include "vector/rtree.hpp"

#include "gtest/gtest.h"

TEST(rtree, basic_uint16_t)
{
  constexpr uint64_t tree_depth = 10;
  constexpr uint64_t node_size = 2;
  constexpr uint64_t node_count = 2046;
  constexpr uint64_t end_count = 1024;

  benlib::rtree<uint16_t> rt(node_size, tree_depth);
  EXPECT_EQ(rt.tree_depth(), tree_depth);
  EXPECT_EQ(rt.node_count(), node_count);
  EXPECT_EQ(rt.node_end_count(), end_count);
}

TEST(rtree, basic_uint32_t)
{
  constexpr uint64_t tree_depth = 10;
  constexpr uint64_t node_size = 2;
  constexpr uint64_t node_count = 2046;
  constexpr uint64_t end_count = 1024;

  benlib::rtree<uint32_t> rt(node_size, tree_depth);
  EXPECT_EQ(rt.tree_depth(), tree_depth);
  EXPECT_EQ(rt.node_count(), node_count);
  EXPECT_EQ(rt.node_end_count(), end_count);
}

TEST(rtree, basic_uint64_t)
{
  constexpr uint64_t tree_depth = 10;
  constexpr uint64_t node_size = 2;
  constexpr uint64_t node_count = 2046;
  constexpr uint64_t end_count = 1024;

  benlib::rtree<uint64_t> rt(node_size, tree_depth);
  EXPECT_EQ(rt.tree_depth(), tree_depth);
  EXPECT_EQ(rt.node_count(), node_count);
  EXPECT_EQ(rt.node_end_count(), end_count);
}

TEST(rtree, basic_string)
{
  constexpr uint64_t tree_depth = 10;
  constexpr uint64_t node_size = 2;
  constexpr uint64_t node_count = 2046;
  constexpr uint64_t end_count = 1024;

  benlib::rtree<std::string> rt(node_size, tree_depth);
  EXPECT_EQ(rt.tree_depth(), tree_depth);
  EXPECT_EQ(rt.node_count(), node_count);
  EXPECT_EQ(rt.node_end_count(), end_count);
}

TEST(rtree, basic_vector)
{
  constexpr uint64_t tree_depth = 10;
  constexpr uint64_t node_size = 2;
  constexpr uint64_t node_count = 2046;
  constexpr uint64_t end_count = 1024;

  benlib::rtree<std::vector<uint64_t>> rt(node_size, tree_depth);
  EXPECT_EQ(rt.tree_depth(), tree_depth);
  EXPECT_EQ(rt.node_count(), node_count);
  EXPECT_EQ(rt.node_end_count(), end_count);
}
