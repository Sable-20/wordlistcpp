cmake_minimum_required(VERSION 4.0)
project(wordlistcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(wordlistcpp main.cpp
        subcommands/fetch/FETCH.hpp
        subcommands/fetch/FETCH.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/cli11)
target_link_libraries(wordlistcpp PRIVATE CLI11::CLI11)