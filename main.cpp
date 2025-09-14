#include <iostream>

#include <cxxopts.hpp>

#include "terminal_mods.hpp"

#define VERSION "0.1.0"
#define AUTHOR "Sable-20"

int main(int argc, const char **argv) {
    std::ostringstream os;
    os  << "<subcommand> [OPTION...]\n\n"
        << UNDERLINE << BOLD << "Available commands:" << RESET "\n\t"
        << "fetch\n";

    std::ostringstream description;
    description << "A " << BOLD << RED << "C++" << RESET << " implementation of " << GREEN << "wordlistctl" << RESET;

   cxxopts::Options options = cxxopts::Options("wordlistcpp", description.str())
    .custom_help(os.str())
    .positional_help("");

    options
        .set_width(80)
        .allow_unrecognised_options()
        .set_tab_expansion()
        .add_options()
            ("h,help", "Help find usage instructions on this program")
            ("v,version", "Print the version information")
            ("command", "The command to use", cxxopts::value<std::string>());

    options.add_options("Fetch")
        ("l,list", "The wordlist to fetch", cxxopts::value<std::string>())
        ("g,group", "group of wordlists to fetch", cxxopts::value<std::string>())
        ("d,decompress", "Whether or not to decompress any compressed files", cxxopts::value<bool>())
        ("w,workers", "Download workers", cxxopts::value<int>()->default_value("10"))
        ("u,useragent", "Useragent to use during fetch", cxxopts::value<std::string>()->default_value("wordlistcpp/v0.1.x"))
        ("b,basedir", "wordlist base directory", cxxopts::value<std::string>()->default_value("/usr/share/wordlists"));


    options.parse_positional({"command"});
    auto result = options.parse(argc, argv);

    if (argc < 2) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    if (result.count("version")) {
        std::cout << "Version: " << VERSION << std::endl;
        exit(0);
    }

    return 0;
}