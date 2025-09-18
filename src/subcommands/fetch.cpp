//
// Created by Sable Ayala on 9/18/25.
//
#include "fetch.hpp"

void setupFetch(CLI::App& app) {
    std::shared_ptr<FetchOptions> options = std::make_shared<FetchOptions>();
    CLI::App* sub = app.add_subcommand("fetch", "Which lists to fetch");

    sub->add_option("-l,--list",options->wordlist, "Wordlist to fetch")->required();
    sub->add_option("-g,--group", options->group, "Group to fetch");
    sub->add_flag("-d,--decompress",options->decompress,"Whether to decompress any compressed files.");
    sub->add_option("-w,--workers",options->workers,"Number of workers to use");
    sub->add_option("-u,--useragent",options->userAgent,"User agent to use during fetch")
        ->default_val("wordlistcpp/v0.1.x");
    sub->add_option("-b,--base-dir",options->baseDirectory,"Base directory for wordlists")
        ->default_val("/usr/share/wordlists");

    sub->callback([options]() {
        runFetch(*options);
    });
}

void runFetch(FetchOptions const& options) {
    throw std::logic_error("Function not yet implemented");
}