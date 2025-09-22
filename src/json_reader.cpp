//
// Created by Sable Ayala on 9/21/25.
//

#include "json_reader.hpp"

JsonReader::JsonReader(std::string const &json_name, std::string const &json_path) {
    std::ifstream file(json_path + "/" + json_name);
    _json = nlohmann::json::parse(file);
}
