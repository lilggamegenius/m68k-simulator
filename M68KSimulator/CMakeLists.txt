cmake_minimum_required(VERSION 2.4)


project(M68KSimulator CXX)
set(SOURCE_FILES M68KSimulator.cpp AddressSpace.cpp )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../build/lib/)

add_library(M68KSimulator
        SHARED
        ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(M68KSimulator Threads::Threads)
TARGET_LINK_LIBRARIES(M68KSimulator D:/Lil-G/workspace/unicorn/libunicorn.a)