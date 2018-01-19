cmake_minimum_required(VERSION 2.4)

project(M68KSimulator CXX)

set(SOURCE_FILES M68KSimulator.cpp AddressSpace.cpp Rom.cpp Ram.cpp AddressTypes/RamAddress.cpp Exceptions/BusException.cpp Exceptions/AddressException.cpp Exceptions/IllegalInstructionException.cpp Exceptions/ZeroDivideException.cpp Exceptions/CHKInstructionException.cpp Exceptions/TRAPVException.cpp Exceptions/PrivilegeViolationException.cpp Exceptions/TraceException.cpp Exceptions/Line1010EmulatorException.cpp Exceptions/Line1111EmulatorException.cpp Exceptions/ErrorException.cpp AddressTypes/Address.cpp AddressTypes/Address.hpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../build/lib/)

add_library(M68KSimulator
        SHARED
        ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(M68KSimulator Threads::Threads unicorn)