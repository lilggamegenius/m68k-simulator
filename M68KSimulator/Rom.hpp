//
// Created by ggonz on 3/9/2017.
//

#pragma once

#define ROM

#include <cstdint>
#include <string>
#include <fstream>

#define romSize 0x400000u

typedef union{
    uint8_t u8[romSize];
    uint16_t u16[romSize / 2];
    uint32_t u32[romSize / 4];

    int8_t s8[romSize];
    int16_t s16[romSize / 2];
    int32_t s32[romSize / 4];
} RomMap;

class Rom {
	static void init();

	static void fill();

public:
    static RomMap* rom;

	static void setRom(std::ifstream);
};
