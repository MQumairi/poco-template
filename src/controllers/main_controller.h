#pragma once

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include "../handlers/default_handler.h"

class MainController: public Poco::Net::HTTPRequestHandlerFactory {
    Poco::Net::HTTPRequestHandler * createRequestHandler(const Poco::Net::HTTPServerRequest &req) override {
        return new DefaultHandler;
    }
};
