//
// Created by Sable Ayala on 9/24/25.
//

#include "http_client.hpp"
#include "terminal_mods.hpp"
#include <httplib.h>
#include <fstream>

void HttpClient::download_range(
        const std::string &host,
        const std::string &path,
        const std::string &partFile,
        long start, long end) {
        httplib::Client cli(host);

        httplib::Headers headers = {
                {"Range", "bytes=" + std::to_string(start) + "-" + std::to_string(end)},
        };

        httplib::Result res = cli.Get(path, headers);

        if (res && (res->status == 206 || res->status == 200)) {
                std::cout << "DOWNLOADING BYTES " + std::to_string(start) + "-" + std::to_string(end) << std::endl;
                std::ofstream out(partFile, std::ios::binary);
                out.write(res->body.data(), res->body.size());
        } else {
                std::cerr << RED << "FAILED TO DOWNLOAD RANGE " << start << +'-' << end << " (HTTP " << (
                        res ? res->status : 0) << "\n";
        }
}

long HttpClient::get_file_size(const std::string &host, const std::string &path) {
        httplib::Client cli(host);
        httplib::Result res = cli.Head(path);

        if (!res || res->status < 200 || res->status >= 300) return -1;

        auto it = res->headers.find("Content-Length");
        if (it != res->headers.end()) {
                return std::stol(it->second);
        }
        return -1;
}

std::tuple<std::string, std::string, bool> HttpClient::split_url(const std::string &url) {
        // returns {host, path, https_flag}
        bool https = false;
        std::string host, path;

        std::string temp = url;
        if (temp.rfind("https://", 0) == 0) {
                https = true;
                temp = temp.substr(8);
        } else if (temp.rfind("http://", 0) == 0) {
                temp = temp.substr(7);
        }

        size_t slash_pos = temp.find('/');
        if (slash_pos != std::string::npos) {
                host = temp.substr(0, slash_pos);
                path = temp.substr(slash_pos);
        } else {
                host = temp;
                path = "/";
        }

        return {host, path, https};
}
