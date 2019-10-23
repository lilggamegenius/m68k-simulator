cmake_minimum_required(VERSION 2.4)

project(M68KSimulator CXX)
set(SOURCE_FILES M68KSimulator.cpp)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../build/lib/)

add_library(M68KSimulator
        SHARED
        ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(M68KSimulator unicorn)