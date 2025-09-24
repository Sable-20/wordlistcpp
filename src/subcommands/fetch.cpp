//
// Created by Sable Ayala on 9/18/25.
//
#include <nlohmann/json.hpp>
#include "fetch.hpp"
#include "../json_reader.hpp"
#include "../terminal_mods.hpp"
/*
 * FORMAT OF REPOSITORY
 * {"bitquark-subdomains-top100000":
 *  {"url":"https://raw.githubusercontent.com/danielmiessler/SecLists/master/Discovery/DNS/bitquark-subdomains-top100000.txt",
 *  "size":"1.43 Mb",
 *  "group":"discovery"
 *  }...}
 */

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
        JsonReader debug_reader = JsonReader(".");
        std::pair<std::string, nlohmann::json> debug_result = debug_reader.getJson(options.wordlist[0]);
        std::cout << RED << debug_result.first << " : " << RESET << debug_result.second["url"] << std::endl;

#endif
#if(RELEASE)
        JsonReader reader = JsonReader(options.baseDirectory);
#endif
        if (options.decompress) {
            std::cout << GREEN << BOLD << "DECOMPRESS ENABLED" << RESET << std::endl;
        }
    }

    std::cout << RED << UNDERLINE << "NOT YET IMPLEMENTED" << RESET << std::endl;
    std::exit(0);
}
