cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(particlesim)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 11)

# Dependencies
include(FetchContent)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
)
FetchContent_GetProperties(raylib)
if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
  set(FETCHCONTENT_QUIET NO)
  FetchContent_Populate(raylib)
  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
endif()

# Our Project

add_executable(particlesim main.cpp particle.cpp particle.h)
#set(raylib_VERBOSE 1)
target_link_libraries(particlesim raylib)
