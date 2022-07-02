#include <cstdint>  // uint32_t, uint64_t
#include <vector>  // std::vector

#include "vector/multi_array.hpp"

#include <benchmark/benchmark.h>

static void multi_array_setvalue_uint32_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    for (uint64_t i = 0; i < width * height; ++i) {
      grid.SetValue(i, 42);
    }
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint32_t));
}
BENCHMARK(multi_array_setvalue_uint32_t_2D)
    ->Name("multi_array_setvalue_uint32_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_square_brace_uint32_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    for (uint64_t i = 0; i < width; ++i) {
      for (uint64_t j = 0; j < height; ++j) {
        grid[i][j] = 42;
      }
    }
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint32_t));
}
BENCHMARK(multi_array_square_brace_uint32_t_2D)
    ->Name("multi_array_square_brace_uint32_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_ptr_uint32_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  auto* ptr = grid.data();

  benchmark::DoNotOptimize(ptr);

  for (auto _ : state) {
    for (uint64_t i = 0; i < width * height; ++i) {
      (*ptr)[i] = 42;
    }
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint32_t));
}
BENCHMARK(multi_array_ptr_uint32_t_2D)
    ->Name("multi_array_ptr_uint32_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_fill_uint8_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint8_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    grid.fill(42);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint8_t));
}
BENCHMARK(multi_array_fill_uint8_t_2D)
    ->Name("multi_array_fill_uint8_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_fill_uint16_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint16_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    grid.fill(42);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint8_t));
}
BENCHMARK(multi_array_fill_uint16_t_2D)
    ->Name("multi_array_fill_uint16_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_fill_uint32_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    grid.fill(42);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint32_t));
}
BENCHMARK(multi_array_fill_uint32_t_2D)
    ->Name("multi_array_fill_uint32_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);

static void multi_array_fill_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint64_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    grid.fill(42);
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height
                          * sizeof(uint32_t));
}
BENCHMARK(multi_array_fill_uint64_t_2D)
    ->Name("multi_array_fill_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4096);
