//
// Created by Sable Ayala on 9/13/25.
//

#include <cxxopts.hpp>

#include "fetch.hpp"

void setup_fetch(cxxopts::Options& options) {
    options.add_options("Fetch")
        ("l,list","The wordlist you wish to fetch" ,cxxopts::value<std::vector<std::string>>());
}