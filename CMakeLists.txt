cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(redis VERSION 6.0)


message(STATUS "Host is: ${CMAKE_HOST_SYSTEM}.  Build target is: ${CMAKE_SYSTEM}")
get_filename_component(REDIS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
message(STATUS "Project root directory is: ${REDIS_ROOT}")
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "Generating release.h...")

add_subdirectory(deps)
add_subdirectory(src)
add_subdirectory(test)

