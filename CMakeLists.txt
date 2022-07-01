cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    vector
    VERSION 0.1.0
    DESCRIPTION "vector lib"
    HOMEPAGE_URL "https://github.com/bensuperpc"
    LANGUAGES NONE
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(vector_vector INTERFACE)
add_library(vector::vector ALIAS vector_vector)
add_library(benlib::vector ALIAS vector_vector)

set_property(
    TARGET vector_vector PROPERTY
    EXPORT_NAME vector
)

target_include_directories(
    vector_vector ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(vector_vector INTERFACE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${vector_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT vector_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of vector"
  )
endif()

include(cmake/dev-mode.cmake)
