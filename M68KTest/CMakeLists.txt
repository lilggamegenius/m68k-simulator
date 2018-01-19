cmake_minimum_required(VERSION 3.1)

project(M68KTest CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../build/bin/)

add_executable(M68KTest ../M68KSimulator/Test/M68KTest.cpp)
TARGET_LINK_LIBRARIES(M68KTest Threads::Threads unicorn M68KSimulator)