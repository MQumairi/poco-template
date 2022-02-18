cmake_minimum_required(VERSION 3.16.3)
project(PocoTemplate)

set(CMAKE_CXX_STANDARD 20)

find_package(Poco REQUIRED
        Foundation
        Util
        Net
        JSON
        Data
        XML)

message("poco found is ${Poco_FOUND}")

add_executable(${PROJECT_NAME} src/main.cpp src/server.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ./src)

target_link_libraries(${PROJECT_NAME} PRIVATE ${Poco_LIBRARIES})

