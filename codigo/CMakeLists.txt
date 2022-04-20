cmake_minimum_required(VERSION 3.16.3)
project(codigo)

set(CMAKE_CXX_STANDARD 14)

add_executable(codigo main.cpp Deliver.cpp Deliver.h DeliverMan.cpp DeliverMan.h Utils.cpp Utils.h)

# Doxygen-generated documentation
find_package(Doxygen)

if(DOXYGEN_FOUND)
    set(DOXYGEN_EXTRACT_ALL "YES")
    set(DOXYGEN_EXTRACT_PRIVATE "YES")
    set(DOXYGEN_EXTRACT_STATIC "YES")
    set(DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
    doxygen_add_docs(docs
            ${PROJECT_SOURCE_DIR})
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)