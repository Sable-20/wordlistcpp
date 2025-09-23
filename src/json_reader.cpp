//
// Created by Sable Ayala on 9/21/25.
//

#include "json_reader.hpp"

JsonReader::JsonReader(std::string const &json_path) {
    std::ifstream file(json_path + "/repo.json");
    _json = nlohmann::json::parse(file);
}
