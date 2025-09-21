cmake_minimum_required(VERSION 3.6)
project(wordlistcpp)

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES
        src/main.cpp
        src/terminal_mods.hpp
        src/subcommands/fetch.hpp
        src/subcommands/fetch.cpp
)

add_compile_definitions("DEBUG=$<CONFIG:Debug>")
add_executable(wordlistcpp ${SRC_FILES})

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
        cli11_proj
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_SHALLOW TRUE
        GIT_TAG v2.5.0
)

FetchContent_MakeAvailable(cli11_proj)

target_link_libraries(wordlistcpp PRIVATE CLI11::CLI11)
target_link_libraries(wordlistcpp PRIVATE nlohmann_json::nlohmann_json)