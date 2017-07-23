//
// Created by ggonz on 3/9/2017.
//

#ifndef M68KSIMULATOR_ROM_H
#define M68KSIMULATOR_ROM_H

#include <cstdint>
#include <string>

#define romSize 0x3FFFFF

typedef union{
    uint8_t u8[romSize];
    uint16_t u16[romSize / 2];
    uint32_t u32[romSize / 4];

    int8_t s8[romSize];
    int16_t s16[romSize / 2];
    int32_t s32[romSize / 4];
} RomMap;

class Rom {
public:
    static RomMap* rom;
    void setRom(std::string filename);
};


#endif //M68KSIMULATOR_ROM_H
