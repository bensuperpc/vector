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

  std::unique_ptr<std::string> ptrA = std::make_unique<std::string>("a");

  gridA.set_value(0, std::move(ptrA));
  gridA.set_value(1, std::make_unique<std::string>("b"));
  gridA.set_value(2, std::make_unique<std::string>("c"));

  auto dataA = gridA.data();

  EXPECT_EQ((*dataA->at(0).get()), "a");
  EXPECT_EQ((*dataA->at(1).get()), "b");
  EXPECT_EQ((*dataA->at(2).get()), "c");
}
