//
// Created by Sable Ayala on 9/18/25.
//

#ifndef WORDLISTCPP_FETCH_HPP
#define WORDLISTCPP_FETCH_HPP

#include <CLI/CLI.hpp>

struct FetchOptions {
    std::vector<std::string>    wordlist;
    std::string                 group;
    bool                        decompress;
    int                         workers;
    std::string                 userAgent;
    std::string                 baseDirectory;
};

void setupFetch(CLI::App& app);

void runFetch(FetchOptions const& options);

#endif //WORDLISTCPP_FETCH_HPP