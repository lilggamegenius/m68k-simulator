cmake_minimum_required(VERSION 2.4)
project(M68KSimulator)
set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -save-temps -std=c++11 -fno-operator-names")

set(SOURCE_FILES M68KSimulator/M68KSimulator.cpp M68KSimulator/AddressSpace.cpp M68KSimulator/Rom.cpp M68KSimulator/Ram.cpp M68KSimulator/Exceptions/BusException.cpp M68KSimulator/Exceptions/AddressException.cpp M68KSimulator/Exceptions/IllegalInstructionException.cpp M68KSimulator/Exceptions/ZeroDivideException.cpp M68KSimulator/Exceptions/CHKInstructionException.cpp M68KSimulator/Exceptions/TRAPVException.cpp M68KSimulator/Exceptions/PrivilegeViolationException.cpp M68KSimulator/Exceptions/TraceException.cpp M68KSimulator/Exceptions/Line1010EmulatorException.cpp M68KSimulator/Exceptions/Line1111EmulatorException.cpp M68KSimulator/Exceptions/ErrorException.cpp M68KSimulator/Address.cpp)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../)

add_library(M68KSimulator
        SHARED
        ${SOURCE_FILES})

