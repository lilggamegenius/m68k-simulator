//
// Created by ggonz on 3/9/2017.
//

#pragma once

#define RAM

#include <cstdint>
#include <malloc.h>
#include "AddressTypes/Address.hpp"


#define ramSize 0x10000u

typedef union{
    uint8_t u8[ramSize];
    uint16_t u16[ramSize / 2];
    uint32_t u32[ramSize / 4];

    int8_t s8[ramSize];
    int16_t s16[ramSize / 2];
    int32_t s32[ramSize / 4];
} RamMap;

class Ram {
public:
    static RamMap* memory;

	Address *operator[](M68kAddr);
};
