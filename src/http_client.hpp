//
// Created by Sable Ayala on 9/24/25.
//

#ifndef WORDLISTCPP_HTTP_CLIENT_HPP
#define WORDLISTCPP_HTTP_CLIENT_HPP
#include <string>


class HttpClient {
private:
public:
    static void download_range(
        const std::string &host,
        const std::string &path,
        const std::string &pathFile,
        long start, long end);

    static long get_file_size(const std::string &host, const std::string &path);

    static std::tuple<std::string, std::string, bool> split_url(const std::string &url);
};


#endif //WORDLISTCPP_HTTP_CLIENT_HPP
