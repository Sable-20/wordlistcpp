cmake_minimum_required(VERSION 3.6)
project(wordlistcpp)

# important options
# -DOPENSSL_ROOT_DIR="$(brew --prefix openssl@3)"

set(CMAKE_CXX_STANDARD 20)

set(SRC_FILES
		src/main.cpp
		src/terminal_mods.hpp
		src/subcommands/fetch.hpp
		src/subcommands/fetch.cpp
		src/subcommands/search_command.cpp
		src/subcommands/search_command.hpp
		src/json_reader.cpp
		src/json_reader.hpp
		src/http_client.cpp
		src/http_client.hpp
)

add_compile_definitions("DEBUG=$<CONFIG:Debug>")
add_compile_definitions("RELEASE=$<CONFIG:Release>")
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

find_package(OpenSSL REQUIRED)

set(HTTPLIB_USE_OPENSSL ON)
FetchContent_Declare(
		cpp-httplib
		GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
		GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(cpp-httplib)

target_link_libraries(wordlistcpp PRIVATE CLI11::CLI11)
target_link_libraries(wordlistcpp PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(wordlistcpp PRIVATE httplib OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(wordlistcpp
		PRIVATE
		"-framework CoreFoundation"
		"-framework CFNetwork"
		"-framework Security"
		/opt/homebrew/opt/openssl@3/lib/libssl.dylib
		/opt/homebrew/opt/openssl@3/lib/libcrypto.dylib
		# ... other libs
)