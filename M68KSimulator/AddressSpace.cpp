//
// Created by ggonz on 3/9/2017.
//

#include "AddressSpace.hpp"

registers dataRegisters[8]; // d0 - d7
registers addressRegisters[9]; // a0-a7, sp, usp
uint32_t programCounter;