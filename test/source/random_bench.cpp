#include <cstdint>  // uint32_t, uint64_t
#include <cstdlib>  // std::rand
#include <random>  // std::mt19937
#include <vector>  // std::vector

#include "vector/random.hpp"  // benlib::random

#include <benchmark/benchmark.h>

#include "vector/utils.hpp"  // _KB, _MB, _GB, _TB

static void random_uint64_t(benchmark::State& state)
{
  uint64_t var = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(var = benlib::random_v2<uint64_t>());
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * sizeof(uint64_t));
}
BENCHMARK(random_uint64_t)->Name("random_uint64_t")->Threads(1);

static void random_uint64_t_ext_rng(benchmark::State& state)
{
  uint64_t var = 0;
  std::mt19937_64 rng {std::random_device {}()};
  for (auto _ : state) {
    benchmark::DoNotOptimize(var = benlib::random<uint64_t>(rng));
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * sizeof(uint64_t));
}
BENCHMARK(random_uint64_t_ext_rng)->Name("random_uint64_t_ext_rng")->Threads(1);

static void random_rand(benchmark::State& state)
{
  uint64_t var = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(var = static_cast<uint64_t>(std::rand()));
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * sizeof(uint64_t));
}
BENCHMARK(random_rand)->Name("random_rand")->Threads(1);

static void random_v1_uint64_t_min_max(benchmark::State& state)
{
  const auto max = static_cast<uint64_t>(state.range(0));
  const auto min = 0;
  uint64_t var = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(var = benlib::random_v1<uint64_t>(min, max));
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * sizeof(uint64_t));
}
BENCHMARK(random_v1_uint64_t_min_max)
    ->Name("random_v1_uint64_t_min_max")
    ->RangeMultiplier(128)
    ->Range(1, 16_GB)
    ->Threads(1);

static void random_v2_uint64_t_min_max(benchmark::State& state)
{
  const auto max = static_cast<uint64_t>(state.range(0));
  const auto min = 0;
  uint64_t var = 0;
  for (auto _ : state) {
    benchmark::DoNotOptimize(var = benlib::random<uint64_t>(min, max));
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * sizeof(uint64_t));
}
BENCHMARK(random_v2_uint64_t_min_max)
    ->Name("random_v2_uint64_t_min_max")
    ->RangeMultiplier(128)
    ->Range(1, 16_GB)
    ->Threads(1);
