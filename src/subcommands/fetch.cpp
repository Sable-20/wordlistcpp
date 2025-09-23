//
// Created by Sable Ayala on 9/18/25.
//
#include "fetch.hpp"
#include "../json_reader.hpp"

FetchCommand::FetchCommand(CLI::App &app) {
    std::shared_ptr<FetchCommand::FetchOptions> options = std::make_shared<FetchCommand::FetchOptions>();
    CLI::App *sub = app.add_subcommand("fetch", "Which lists to fetch");

    sub->add_option("-l,--list", options->wordlist, "Wordlist to fetch")->required();
    sub->add_option("-g,--group", options->group, "Group to fetch");
    sub->add_flag("-d,--decompress", options->decompress, "Whether to decompress any compressed files.");
    sub->add_option("-w,--workers", options->workers, "Number of workers to use");
    sub->add_option("-u,--useragent", options->userAgent, "User agent to use during fetch")
            ->default_val("wordlistcpp/v0.1.x");
    sub->add_option("-b,--base-dir", options->baseDirectory, "Base directory for wordlists")
            ->default_val("/usr/share/wordlists")->check(CLI::ExistingPath);

    sub->callback([options]() {
        FetchCommand::runFetch(*options);
    });
}

void FetchCommand::runFetch(FetchOptions const &options) {
    if (options.wordlist.empty()) {
        std::cerr << "You must specify a wordlist to fetch" << std::endl;
        std::exit(1);
    }
    // TODO: start parsing the arguments for after fetching
    // TODO: parse json
    // TODO: implement fuzzy search
    if (!options.wordlist.empty()) {
#if(DEBUG)
        // TODO: parse json locally
        JsonReader reader = JsonReader(".");
#endif
    }

    throw std::logic_error("Not implemented yet");
}
