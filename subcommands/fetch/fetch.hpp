//
// Created by Sable Ayala on 9/13/25.
//

#ifndef WORDLISTCPP_FETCH_HPP
#define WORDLISTCPP_FETCH_HPP

#include <cxxopts.hpp>

typedef struct {
    std::vector<std::string>    list;
    int                         workers;
    std::string                 output;
} FetchOptions;

void setup_fetch(std::shared_ptr<cxxopts::Options> options);
void parse_fetch(cxxopts::Options &options);

#endif //WORDLISTCPP_FETCH_HPP