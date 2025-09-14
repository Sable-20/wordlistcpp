#include <iostream>

#include <cxxopts.hpp>

#include "subcommands/fetch/fetch.hpp"

#define VERSION "0.1.0"
#define AUTHOR "Sable-20"

int main(int argc, const char **argv) {

   cxxopts::Options options = cxxopts::Options("wordlistcpp", "A C++ implementation of wordlistctl");

    // setup positional arguments
    options.add_options()
        ("command", "Which command to execute (i.e. fetch, search...)", cxxopts::value<std::string>());

    setup_fetch(options);

    options.parse_positional({"command"});
    auto result = options.parse(argc, argv);

    return 0;
}