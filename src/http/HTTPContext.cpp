//
// Created by siskinc on 18-4-9.
//

#include "HTTPContext.hpp"

http::HTTPContext::HTTPContext(std::string data)
{
    InitData(std::move(data));
}

void http::HTTPContext::InitData(std::string data)
{
    this->inited = true;
    HTTPParser parser(data);
    this->code = parser.GetCode();
    this->method = parser.GetMethod();
    this->url = parser.GetUrl();
    this->HTTPVersion_ = parser.GetHTTPVersion();
    this->headers = parser.GetHeaders();
    this->cookies = HTTPCookies(this->headers.at("Cookie"));
}

http::HTTPContext::HTTPContext()
{
    this->inited = false;
}

http::HTTPCode http::HTTPContext::GetCode() const
{
    return code;
}

const std::string &http::HTTPContext::GetMethod() const
{
    return method;
}

const std::string &http::HTTPContext::GetUrl() const
{
    return url;
}

http::HTTPVersion http::HTTPContext::GetHTTPVersion_() const
{
    return HTTPVersion_;
}

bool http::HTTPContext::IsInited() const
{
    return inited;
}
