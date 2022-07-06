#include <cstdint>  // uint32_t, uint64_t
#include <random>  // std::mt19937
#include <vector>  // std::vector

#include "vector/utils.hpp"  // _KB, _MB, _GB, _TB

#include "gtest/gtest.h"

TEST(vector_utils, basic_uint16_t)
{
  const uint16_t kb_var = 4_KB;
  EXPECT_EQ(kb_var, 4096);
}

TEST(vector_utils, basic_uint32_t)
{
  const uint32_t kb_var = 4_KB;
  EXPECT_EQ(kb_var, 4096);
  const uint32_t mb_var = 4_MB;
  EXPECT_EQ(mb_var, 4194304);
  const uint32_t gb_var = 1_GB;
  EXPECT_EQ(gb_var, 1073741824);
}

TEST(vector_utils, basic_uint64_t)
{
  const uint64_t kb_var = 4_KB;
  EXPECT_EQ(kb_var, 4096);
  const uint64_t mb_var = 4_MB;
  EXPECT_EQ(mb_var, 4194304);
  const uint64_t gb_var = 4_GB;
  EXPECT_EQ(gb_var, 4294967296);
}
