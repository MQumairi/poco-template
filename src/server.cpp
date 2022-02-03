#include "server.h"
#include <iostream>

#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

#include "controllers/main_controller.h"

using namespace Poco::Net;
using namespace Poco::Util;

int Server::main(const std::vector<std::string> &args) {
    //Setup HTTP server
    auto* params = new HTTPServerParams;
    auto port = 5000;
    ServerSocket socket(port);
    HTTPServer httpServer(new MainController, socket, params);
    httpServer.start();
    std::cout << "Started server: http://localhost:" << port << "/" << std::endl;
    waitForTerminationRequest();
    std::cout << "Shutting server down..." << std::endl;
    httpServer.stop();
    return Application::main(args);
}
