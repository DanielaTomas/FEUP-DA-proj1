cmake_minimum_required(VERSION 3.17)
project(codigo)

set(CMAKE_CXX_STANDARD 14)

add_executable(codigo main.cpp Deliver.cpp Deliver.h DeliverMan.cpp DeliverMan.h Utils.cpp Utils.h)