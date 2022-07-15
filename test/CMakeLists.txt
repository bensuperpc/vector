cmake_minimum_required(VERSION 3.14)

project(vectorTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)
include(../cmake/windows-set-path.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(vector REQUIRED)
  enable_testing()
endif()

find_package(OpenMP 3.0)

# ---- Tests ----

#add_executable(vector_test source/vector_test.cpp)
#target_link_libraries(vector_test PRIVATE benlib::vector)
#target_compile_features(vector_test PRIVATE cxx_std_20)

#add_test(NAME vector_test COMMAND vector_test)

function(add_test_fn TEST_NAME)
  add_executable("${TEST_NAME}" "source/${TEST_NAME}.cpp")
  target_link_libraries("${TEST_NAME}" PRIVATE vector::vector gtest_main)
  if (OpenMP_FOUND OR OpenMP_CXX_FOUND)
    target_link_libraries("${TEST_NAME}" PRIVATE OpenMP::OpenMP_CXX)
  endif()

  add_test(NAME "${TEST_NAME}" COMMAND $<TARGET_FILE:${TEST_NAME}>)
  #target_compile_features("${TEST_NAME}" PRIVATE cxx_std_20)
endfunction()

function(add_bench_fn BENCH_NAME)
  add_executable("${BENCH_NAME}" "source/${BENCH_NAME}.cpp")
  target_link_libraries("${BENCH_NAME}" PRIVATE vector::vector benchmark::benchmark_main)

  if (OpenMP_FOUND OR OpenMP_CXX_FOUND)
    target_link_libraries("${BENCH_NAME}" PRIVATE OpenMP::OpenMP_CXX)
  endif()

  if(NOT CMAKE_BUILD_TYPE MATCHES Debug AND NOT CMAKE_BUILD_TYPE MATCHES Coverage)
    add_test(NAME "${BENCH_NAME}" COMMAND $<TARGET_FILE:${BENCH_NAME}>)
  elseif()
    message(STATUS "Disable ${BENCH_NAME}, Performance benchmark test only run on Release/RelWithDebInfo/MinSizeRel")
  endif()
  #target_compile_features("${TEST_NAME}" PRIVATE cxx_std_20)
endfunction()

if(NOT WIN32)
include(../cmake/lib/gtest.cmake)
include(../cmake/lib/benchmark.cmake)
  # Add tests
  add_test_fn(vector_random_test)
  add_test_fn(multi_array_advanced_test)
  add_test_fn(multi_array_basic_test)
  add_test_fn(multi_array_smart_ptr_test)
  
  add_test_fn(utils_test)
  add_test_fn(rtree_test)
  
  # Add bench
  add_bench_fn(vector_random_bench)
  add_bench_fn(multi_array_bench)
  add_bench_fn(random_bench)
endif()


# ---- End-of-file commands ----

add_folders(Test)
