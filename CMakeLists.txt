cmake_minimum_required(VERSION 3.15.0)

project(HTTP-Client LANGUAGES CXX)

cmake_project_version(VERSION 0.0.1)

add_library(utils STATIC include/utils.h src/utils.cpp)

add_executable(client client.cpp)

target_link_libraries(client utils)
