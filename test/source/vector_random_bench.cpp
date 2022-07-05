#include <cstdint>  // uint32_t, uint64_t
#include <random>  // std::mt19937
#include <vector>  // std::vector

#include "vector/vector_random.hpp"  // benlib::random

#include <benchmark/benchmark.h>

#include "vector/utils.hpp"  // _KB, _MB, _GB, _TB

static void random_32bit_uint32_t(benchmark::State& state)
{
  const auto size = static_cast<uint64_t>(state.range(0));

  std::vector<uint32_t> vect(size);

  benchmark::DoNotOptimize(vect);
  for (auto _ : state) {
    benlib::random<uint32_t, std::mt19937>(vect);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * size);
  state.SetBytesProcessed(state.iterations() * size * sizeof(uint32_t));
}
BENCHMARK(random_32bit_uint32_t)->Name("random_32bit_uint32_t")->RangeMultiplier(8)->Range(8, 2_MB);

static void random_32bit_uint32_t_local(benchmark::State& state)
{
  const auto size = static_cast<uint64_t>(state.range(0));
  std::vector<uint32_t> vect(size);
  benchmark::DoNotOptimize(vect);

  constexpr auto min = std::numeric_limits<uint32_t>::min();
  constexpr auto max = std::numeric_limits<uint32_t>::max();

  std::random_device rnd_device;
  std::mt19937 rng;
  rng.seed(rnd_device());

  for (auto _ : state) {
    benlib::random<uint32_t, std::mt19937>(vect, min, max, rng);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * size);
  state.SetBytesProcessed(state.iterations() * size * sizeof(uint32_t));
}
BENCHMARK(random_32bit_uint32_t_local)->Name("random_32bit_uint32_t_local")->RangeMultiplier(8)->Range(8, 2_MB);

static void random_64bit_uint32_t(benchmark::State& state)
{
  const auto size = static_cast<uint64_t>(state.range(0));

  std::vector<uint32_t> vect(size);

  benchmark::DoNotOptimize(vect);
  for (auto _ : state) {
    benlib::random<uint32_t, std::mt19937_64>(vect);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * size);
  state.SetBytesProcessed(state.iterations() * size * sizeof(uint32_t));
}
BENCHMARK(random_64bit_uint32_t)->Name("random_64bit_uint32_t")->RangeMultiplier(8)->Range(8, 2_MB);

static void random_64bit_uint32_t_local(benchmark::State& state)
{
  const auto size = static_cast<uint64_t>(state.range(0));
  std::vector<uint32_t> vect(size);
  benchmark::DoNotOptimize(vect);

  constexpr auto min = std::numeric_limits<uint32_t>::min();
  constexpr auto max = std::numeric_limits<uint32_t>::max();

  std::random_device rnd_device;
  std::mt19937_64 rng;
  rng.seed(rnd_device());

  for (auto _ : state) {
    benlib::random<uint32_t, std::mt19937_64>(vect, min, max, rng);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * size);
  state.SetBytesProcessed(state.iterations() * size * sizeof(uint32_t));
}
BENCHMARK(random_64bit_uint32_t_local)->Name("random_64bit_uint32_t_local")->RangeMultiplier(8)->Range(8, 2_MB);
