//
// Created by Sable Ayala on 9/21/25.
//

#ifndef WORDLISTCPP_SEARCH_COMMAND_HPP
#define WORDLISTCPP_SEARCH_COMMAND_HPP

#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>

class SearchCommand {
private:
    struct SearchOptions {
        bool                        local;
        std::string                 base_dir;
        std::vector<std::string>    index;
    };

    static void runSearch(const SearchOptions& options);
public:
    explicit SearchCommand(CLI::App& app);
};


#endif //WORDLISTCPP_SEARCH_COMMAND_HPP