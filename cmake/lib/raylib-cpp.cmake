cmake_minimum_required(VERSION 3.14.0)

include(FetchContent)

find_package(raylib_cpp QUIET)

if (NOT raylib_cpp_FOUND)
    FetchContent_Declare(raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG a8f803edae6db67dafa1f84c1099f1bbc74925ef # 2022-07-01
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()