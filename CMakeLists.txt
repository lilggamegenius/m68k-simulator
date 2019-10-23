cmake_minimum_required(VERSION 2.8.4)
project(M68KSimulatorProject CXX)

set(CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-operator-names")

add_subdirectory(M68KSimulator)
add_subdirectory(M68KTest)
