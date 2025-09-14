cmake_minimum_required(VERSION 3.14)
project(wordlistcpp)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES
        main.cpp
        terminal_mods.hpp
)

add_executable(wordlistcpp ${SRC_FILES})

include(FetchContent)
FetchContent_Declare(
        simdjson
        GIT_REPOSITORY https://github.com/simdjson/simdjson.git
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(simdjson)

FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(cxxopts)

target_link_libraries(wordlistcpp PRIVATE cxxopts::cxxopts)
target_link_libraries(wordlistcpp PRIVATE simdjson)