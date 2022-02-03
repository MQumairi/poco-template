#pragma once

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

class DefaultHandler: public Poco::Net::HTTPRequestHandler {
    void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &res) override {
        res.setContentType("application/json");
        std::ostream &out = res.send();
        out << "{\"message\": \"hello world\"}";
        out.flush();
    }
};