//
// Created by siskinc on 18-4-3.
//

#ifndef NET_HTTPVERSION_HPP
#define NET_HTTPVERSION_HPP

namespace http {

enum HTTPVersion
{
    HTTP1_1 = 11,
    HTTP1_0 = 10,
};

namespace http_version {

namespace {

HTTPVersion GetHTTPVersion(std::string version)
{
    if (version == "HTTP/1.1")
    {
        return HTTP1_1;
    }

    if (version == "HTTP/1.0")
    {
        return HTTP1_0;
    }
}

const std::string HTTPVersion2Str(const HTTPVersion version)
{
    std::string ret;
    switch (version)
    {
        case HTTP1_0:
            return "HTTP/1.0";
        case HTTP1_1:
            return "HTTP/1.1";
        default:
            return "";
    }
}

}
}

}
#endif //NET_HTTPVERSION_HPP
