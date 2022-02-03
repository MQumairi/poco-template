#include <iostream>
#include "server.h"

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    Server server;
    server.run(argc, argv);
    return 0;
}
