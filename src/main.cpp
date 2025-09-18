#include <iostream>

#include <CLI/CLI.hpp>

#include "subcommands/fetch.hpp"

#include "terminal_mods.hpp"

#define VERSION "0.1.0"
#define AUTHOR "Sable-20"

int main(int argc, char** argv) {
    CLI::App app{"wordlistcpp -- a C++ implementation of wordlistctl"};

    CLI::App* search_cmd = app.add_subcommand("search", "Which lists to search for");
    CLI::App* fetch_cmd = app.add_subcommand("fetch", "Which list to fetch");
    CLI::App* list_cmd = app.add_subcommand("list", "List wordlists");

    CLI11_PARSE(app, argc, argv);
    return 0;
}