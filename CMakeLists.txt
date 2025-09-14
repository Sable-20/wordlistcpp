cmake_minimum_required(VERSION 4.0)
project(wordlistcpp)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES
    subcommands/fetch/fetch.cpp)

set(HEADER_FILES
    subcommands/fetch/fetch.hpp)

add_executable(wordlistcpp main.cpp ${SRC_FILES} ${HEADER_FILES})

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/cxxopts)
target_link_libraries(wordlistcpp PRIVATE cxxopts::cxxopts)