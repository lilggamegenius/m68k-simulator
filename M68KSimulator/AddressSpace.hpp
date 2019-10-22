//
// Created by ggonz on 3/9/2017.
//
#pragma once

#include <cstdint>
#include "Registers.hpp"


#define ramSize 0x10000u

typedef union{
	uint8_t u8[ramSize];
	uint16_t u16[ramSize / 2];
	uint32_t u32[ramSize / 4];

	int8_t s8[ramSize];
	int16_t s16[ramSize / 2];
	int32_t s32[ramSize / 4];
} RamMap;


#define romSize 0x400000u

typedef union{
	uint8_t u8[romSize];
	uint16_t u16[romSize / 2];
	uint32_t u32[romSize / 4];

	int8_t s8[romSize];
	int16_t s16[romSize / 2];
	int32_t s32[romSize / 4];
} RomMap;

struct AddressSpace {
public:
	RomMap rom;                                         // $000000-$3FFFFF  Cartridge ROM/RAM
    uint8_t reserved1[0x400000];                        // $400000-$7FFFFF	Reserved (used by the Sega CD and 32x)
    uint8_t reserved2[0x200000];                        // $800000-$9FFFFF	Reserved (used by the 32x?)
    uint8_t z80Addressing[0x10000];                     // $A00000-$A0FFFF	Z80 addressing space
    const uint16_t versionRegister = 0;                 // $A10000-$A10001	Version register (read-only word-long)
    uint16_t control1Data;                              // $A10002-$A10003	Controller 1 data
    uint16_t control2Data;                              // $A10004-$A10005	Controller 2 data
    uint16_t expansionPortData;                         // $A10006-$A10007	Expansion port data
    uint16_t control1Control;                           // $A10008-$A10009	Controller 1 control
    uint16_t control2Control;                           // $A1000A-$A1000B	Controller 2 control
    uint16_t expansionPortControl;                      // $A1000C-$A1000D	Expansion port control
    uint16_t control1SerialTrans;	                    // $A1000E-$A1000F	Controller 1 serial transmit
    uint16_t control1SerialRecev;                       // $A10010-$A10011	Controller 1 serial receive
    uint16_t control1SerialControl;	                    // $A10012-$A10013	Controller 1 serial control
    uint16_t control2SerialTrans;                       // $A10014-$A10015	Controller 2 serial transmit
    uint16_t control2SerialRecev;                       // $A10016-$A10017	Controller 2 serial receive
    uint16_t control2SerialControl;                     // $A10018-$A10019	Controller 2 serial control
    uint16_t expansionPortSerialTrans;	                // $A1001A-$A1001B	Expansion port serial transmit
    uint16_t expansionPortSerialRecev;	                // $A1001C-$A1001D	Expansion port serial receive
    uint16_t expansionPortSerialControl;                // $A1001E-$A1001F	Expansion port serial control
    const uint8_t reserved3[0xFE0] = {0};               // $A10020-$A10FFF	Reserved
    uint8_t memoryModeRegister;                         // $A11000	        Memory mode register
    const uint8_t reserved4[0xFE] = {0};                // $A11002-$A110FF	Reserved
    uint16_t z80BusRequest;                             // $A11100-$A11101	Z80 bus request
    const uint8_t reserved5[0xFE] = {0};                // $A11102-$A111FF	Reserved
    uint16_t z80Reset;			                        // $A11200-$A11201	Z80 reset
    uint32_t TMSS;			                            // $A14000-$A14003	TMSS register
    const uint8_t reserved6[0x1EBFFC] = {0};            // $A14004-$BFFFFF	Reserved
	struct{
		uint16_t VDPData;					            // $C00000-$C00001	VDP data
		uint16_t VDPDataMirror;                         // $C00002-$C00003	VDP data (mirror)
		uint16_t VDPControl;				            // $C00004-$C00005	VDP control
		uint16_t VDPControlMirror;                      // $C00006-$C00007	VDP control (mirror)
		uint16_t VDPHVCounter;                          // $C00008-$C00009	VDP HV counter
		uint8_t reserved7[0x06];                        // $C0000A-$C00010	Reserved
		uint8_t PSGOutput;                              // $C00011	        PSG output
		const uint8_t reserved8[0x1FFFEE] = {0};        // $C00012-$DFFFFF	Reserved
	} VDP;
    RomMap ram;                                         // $E00000-$FFFFFF	68000 RAM

};
