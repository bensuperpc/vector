#include <cstdint>  // uint32_t, uint64_t
#include <random>  // std::mt19937
#include <vector>  // std::vector

#include "vector/vector_random.hpp"  // benlib::random

#include "gtest/gtest.h"

TEST(vector_random, basic_mt19937_uint64_t)
{
  std::vector<uint64_t> vect = std::vector<uint64_t>(10, 0);
  EXPECT_EQ(vect[0], 0);
  benlib::random<uint64_t, std::mt19937>(vect);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, basic_mt19937_64_uint64_t)
{
  std::vector<uint64_t> vect = std::vector<uint64_t>(10, 0);
  EXPECT_EQ(vect[0], 0);
  benlib::random<uint64_t, std::mt19937_64>(vect);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, basic_mt19937_float)
{
  std::vector<float> vect = std::vector<float>(10, 0);
  EXPECT_EQ(vect[0], 0);
  benlib::random<float, std::mt19937>(vect);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, basic_mt19937_64_float)
{
  std::vector<float> vect = std::vector<float>(10, 0);
  EXPECT_EQ(vect[0], 0);
  benlib::random<float, std::mt19937_64>(vect);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, min_max_mt19937_uint64_t)
{
  std::vector<uint64_t> vect = std::vector<uint64_t>(10, 0);
  EXPECT_EQ(vect[0], 0);
  constexpr auto min = std::numeric_limits<uint64_t>::min();
  constexpr auto max = std::numeric_limits<uint64_t>::max();
  benlib::random<uint64_t, std::mt19937>(vect, min, max);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, min_max_mt19937_64_uint64_t)
{
  std::vector<uint64_t> vect = std::vector<uint64_t>(10, 0);
  EXPECT_EQ(vect[0], 0);
  constexpr auto min = std::numeric_limits<uint64_t>::min();
  constexpr auto max = std::numeric_limits<uint64_t>::max();
  benlib::random<uint64_t, std::mt19937_64>(vect, min, max);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, seed_mt19937_uint64_t)
{
  std::vector<uint64_t> vect = std::vector<uint64_t>(10, 0);
  EXPECT_EQ(vect[0], 0);

  constexpr auto min = std::numeric_limits<uint64_t>::min();
  constexpr auto max = std::numeric_limits<uint64_t>::max();
  std::random_device rnd_device;
  std::mt19937 rng;
  rng.seed(rnd_device());
  benlib::random<uint64_t, std::mt19937>(vect, min, max, rng);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}

TEST(vector_random, seed_mt19937_64_uint64_t)
{
  std::vector<uint64_t> vect = std::vector<uint64_t>(10, 0);
  EXPECT_EQ(vect[0], 0);
  constexpr auto min = std::numeric_limits<uint64_t>::min();
  constexpr auto max = std::numeric_limits<uint64_t>::max();

  std::random_device rnd_device;
  std::mt19937_64 rng;
  rng.seed(rnd_device());
  benlib::random<uint64_t, std::mt19937_64>(vect, min, max, rng);
  EXPECT_NE(vect[0], 0);
  EXPECT_NE(vect[0], vect[1]);
}
