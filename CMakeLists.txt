cmake_minimum_required(VERSION 3.16.3)
project(PocoTemplate)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED
        Foundation
        Util
        Net
        JSON
        Data)

message("poco found is ${Poco_FOUND}")

include_directories(${Poco_INCLUDE_DIRS})

link_libraries(${Poco_LIBRARIES})

add_executable(PocoTemplate src/main.cpp src/server.cpp)
