#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include <benchmark/benchmark.h>

static void multi_array_setvalue2D(benchmark::State& state)
{
  const auto width = state.range(0);
  const auto height = state.range(0);
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    for (uint64_t i = 0; i < width * height; ++i) {
      grid.SetValue(i, 384);
    }
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint32_t));
}
BENCHMARK(multi_array_setvalue2D)
    ->Name("multi_array_setvalue2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_setvalue3D(benchmark::State& state)
{
  const auto width = state.range(0);
  const auto height = state.range(0);
  const auto depth = state.range(0);
  std::vector<uint64_t> v = {width, height, depth};
  auto grid = benlib::MultiVector<uint32_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    for (uint64_t i = 0; i < width * height * depth; ++i) {
      grid.SetValue(i, 384);
    }
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height * depth);
  state.SetBytesProcessed(state.iterations() * width * height * depth * sizeof(uint32_t));
}
BENCHMARK(multi_array_setvalue2D)
    ->Name("multi_array_setvalue2D")
    ->RangeMultiplier(4)
    ->Range(16, 1024);
