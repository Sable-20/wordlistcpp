cmake_minimum_required(VERSION 4.0)
project(wordlistcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(wordlistcpp main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(lib/cxxopts)
target_include_directories(wordlistcpp PUBLIC cxxopts)
target_link_libraries(wordlistcpp PUBLIC cxxopts)