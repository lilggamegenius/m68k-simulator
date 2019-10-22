cmake_minimum_required(VERSION 2.4)
project(M68KSimulatorProject CXX)

include_directories(../unicorn/include)

set(CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-operator-names")

add_subdirectory(M68KSimulator)
add_subdirectory(M68KTest)
