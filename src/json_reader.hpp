//
// Created by Sable Ayala on 9/21/25.
//

#ifndef WORDLISTCPP_JSON_READER_HPP
#define WORDLISTCPP_JSON_READER_HPP

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

class JsonReader {
private:
    nlohmann::json _json;

public:
    // no discard?
    [[nodiscard]] std::pair<std::string, nlohmann::json> getJson(std::string const &key) const {
        return std::pair<std::string, nlohmann::json>{key, _json.at(key)};
    }

    explicit JsonReader(std::string const &json_path);
};
#endif //WORDLISTCPP_JSON_READER_HPP
