#pragma once

#include <Poco/Util/ServerApplication.h>

class Server: public Poco::Util::ServerApplication {
public:
    int main(const std::vector<std::string> &args) override;
};