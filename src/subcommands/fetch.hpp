//
// Created by Sable Ayala on 9/18/25.
//

#ifndef WORDLISTCPP_FETCH_HPP
#define WORDLISTCPP_FETCH_HPP

#include <functional>
#include <CLI/CLI.hpp>

class FetchCommand {
private:
    struct FetchOptions {
        std::vector<std::string>    wordlist;
        std::string                 group;
        bool                        decompress;
        int                         workers;
        std::string                 userAgent;
        std::string                 baseDirectory;
    };

    static void runFetch(FetchOptions const& options);
public:
    explicit FetchCommand(CLI::App& app);
};

#endif //WORDLISTCPP_FETCH_HPP