cmake_minimum_required(VERSION 3.14.0)

include(FetchContent)

FetchContent_Declare(
  backward
  GIT_REPOSITORY https://github.com/bombela/backward-cpp.git
  GIT_TAG 74184aad55777f0c04227edd56c3dea84b6a272f) # 18-06-2022

FetchContent_MakeAvailable(backward)
