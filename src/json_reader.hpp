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
    [[nodiscard]] const nlohmann::json &getJson() const {
        return _json;
    }

    JsonReader(std::string const &json_name, std::string const &json_path);
};
#endif //WORDLISTCPP_JSON_READER_HPP
