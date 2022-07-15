#include <cstdint>  // uint32_t, uint64_t
#include <cstdlib>  // std::rand
#include <random>  // std::mt19937
#include <vector>  // std::vector

#include "vector/multi_array.hpp"  // benlib::multi_array

#include <benchmark/benchmark.h>

#include "vector/utils.hpp"  // _KB, _MB, _GB, _TB

static void multi_array_set_value_uint32_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint32_t>(v);
  grid.fill(0);
  benchmark::DoNotOptimize(grid);

  for (auto _ : state) {
    for (uint64_t i = 0; i < width * height; ++i) {
      grid.set_value(i, 42);
    }
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint32_t));
}
BENCHMARK(multi_array_set_value_uint32_t_2D)
    ->Name("multi_array_set_value_uint32_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB);

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
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint32_t));
}
BENCHMARK(multi_array_square_brace_uint32_t_2D)
    ->Name("multi_array_square_brace_uint32_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB);

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
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint32_t));
}
BENCHMARK(multi_array_ptr_uint32_t_2D)->Name("multi_array_ptr_uint32_t_2D")->RangeMultiplier(8)->Range(8, 4_KB);

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
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint8_t));
}
BENCHMARK(multi_array_fill_uint8_t_2D)->Name("multi_array_fill_uint8_t_2D")->RangeMultiplier(8)->Range(8, 4_KB);

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
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint32_t));
}
BENCHMARK(multi_array_fill_uint64_t_2D)->Name("multi_array_fill_uint64_t_2D")->RangeMultiplier(8)->Range(8, 4_KB);

static void multi_array_add_operator_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto gridA = benlib::multi_array<uint64_t>(v);
  gridA.fill(10);
  benchmark::DoNotOptimize(gridA);
  auto gridB = benlib::multi_array<uint64_t>(v);
  gridB.fill(32);
  benchmark::DoNotOptimize(gridB);

  for (auto _ : state) {
    gridA = gridA + gridB;
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint64_t));
}
BENCHMARK(multi_array_add_operator_uint64_t_2D)
    ->Name("multi_array_add_operator_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB);

static void multi_array_sub_operator_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto gridA = benlib::multi_array<uint64_t>(v);
  gridA.fill(64);
  benchmark::DoNotOptimize(gridA);
  auto gridB = benlib::multi_array<uint64_t>(v);
  gridB.fill(10);
  benchmark::DoNotOptimize(gridB);

  for (auto _ : state) {
    gridA = gridA - gridB;
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint64_t));
}
BENCHMARK(multi_array_sub_operator_uint64_t_2D)
    ->Name("multi_array_sub_operator_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB);

static void multi_array_mult_operator_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto gridA = benlib::multi_array<uint64_t>(v);
  gridA.fill(128);
  benchmark::DoNotOptimize(gridA);
  auto gridB = benlib::multi_array<uint64_t>(v);
  gridB.fill(5);
  benchmark::DoNotOptimize(gridB);

  for (auto _ : state) {
    gridA = gridA * gridB;
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint64_t));
}
BENCHMARK(multi_array_mult_operator_uint64_t_2D)
    ->Name("multi_array_mult_operator_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB);

static void multi_array_div_operator_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto gridA = benlib::multi_array<uint64_t>(v);
  gridA.fill(128);
  benchmark::DoNotOptimize(gridA);
  auto gridB = benlib::multi_array<uint64_t>(v);
  gridB.fill(8);
  benchmark::DoNotOptimize(gridB);

  for (auto _ : state) {
    gridA = gridA / gridB;
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint64_t));
}
BENCHMARK(multi_array_div_operator_uint64_t_2D)
    ->Name("multi_array_div_operator_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB);

static void multi_array_get_value_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint64_t>(v);
  grid.fill(rand() % 256);
  uint64_t tmp = 0;
  benchmark::DoNotOptimize(grid);
  benchmark::DoNotOptimize(tmp);

  for (auto _ : state) {
    benchmark::DoNotOptimize(tmp = grid.get_value(rand() % 8));
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint64_t));
}
BENCHMARK(multi_array_get_value_uint64_t_2D)
    ->Name("multi_array_get_value_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB)
    ->Threads(1);

static void multi_array_data_uint64_t_2D(benchmark::State& state)
{
  const auto width = static_cast<uint64_t>(state.range(0));
  const auto height = static_cast<uint64_t>(state.range(0));
  std::vector<uint64_t> v = {width, height};
  auto grid = benlib::multi_array<uint64_t>(v);
  grid.fill(rand() % 256);
  uint64_t* tmp = 0;

  for (auto _ : state) {
    benchmark::DoNotOptimize(tmp = grid.data(rand() % 8));
    benchmark::ClobberMemory();
  }

  state.SetItemsProcessed(state.iterations() * width * height);
  state.SetBytesProcessed(state.iterations() * width * height * sizeof(uint64_t));
}
BENCHMARK(multi_array_data_uint64_t_2D)
    ->Name("multi_array_data_uint64_t_2D")
    ->RangeMultiplier(8)
    ->Range(8, 4_KB)
    ->Threads(1);
