//
// Created by ggonz on 3/9/2017.
//

#pragma once

#include <cstdint>

#define M68kRamOffset 0xE00000
#define M68kRamOffsetMirror 0xFF0000

typedef uint32_t M68kAddr;
typedef union{
    uint8_t u8[4];
    uint16_t u16[2];
    uint32_t u32;

    int8_t s8[4];
    int16_t s16[2];
    int32_t s32;
} registers;

extern registers dataRegisters[8]; // d0 - d7
extern registers *addressRegisters[9]; // a0-a7, sp, usp
extern uint32_t programCounter;

enum Size{
    Byte, Word, Longword
};

enum DataRegister{
    d0, d1, d2, d3, d4, d5, d6, d7
};

enum AddressRegister {
    a0, a1, a2, a3, a4, a5, a6, a7, sp=a7, usp
};

class AddressSpace;
class Ram;

#include "Ram.h"
#include "Rom.h"

class AddressSpace {
public:
    static Rom rom;                                 // $000000-$3FFFFF  Cartridge ROM/RAM
                                                    // $400000-$7FFFFF	Reserved (used by the Sega CD and 32x)
                                                    // $800000-$9FFFFF	Reserved (used by the 32x?)
                                                    // $A00000-$A0FFFF	Z80 addressing space
    static const uint16_t versionRegister;          // $A10000-$A10001	Version register (read-only word-long)
    static uint16_t control1Data;                   // $A10002-$A10003	Controller 1 data
    static uint16_t control2Data;                   // $A10004-$A10005	Controller 2 data
    static uint16_t expansionPortData;              // $A10006-$A10007	Expansion port data
    static uint16_t control1Control;                // $A10008-$A10009	Controller 1 control
    static uint16_t control2Control;                // $A1000A-$A1000B	Controller 2 control
    static uint16_t expansionPortControl;           // $A1000C-$A1000D	Expansion port control
    static uint16_t control1SerialTrans;	        // $A1000E-$A1000F	Controller 1 serial transmit
    static uint16_t control1SerialRecev;            // $A10010-$A10011	Controller 1 serial receive
    static uint16_t control1SerialControl;	        // $A10012-$A10013	Controller 1 serial control
    static uint16_t control2SerialTrans;            // $A10014-$A10015	Controller 2 serial transmit
    static uint16_t control2SerialRecev;            // $A10016-$A10017	Controller 2 serial receive
    static uint16_t control2SerialControl;          // $A10018-$A10019	Controller 2 serial control
    static uint16_t expansionPortSerialTrans;	    // $A1001A-$A1001B	Expansion port serial transmit
    static uint16_t expansionPortSerialRecev;	    // $A1001C-$A1001D	Expansion port serial receive
    static uint16_t expansionPortSerialControl;     // $A1001E-$A1001F	Expansion port serial control
                                                    // $A10020-$A10FFF	Reserved
    static uint8_t memoryModeRegister;              // $A11000	Memory mode register
                                                    // $A11002-$A110FF	Reserved
    static uint16_t z80BusRequest;                  // $A11100-$A11101	Z80 bus request
                                                    // $A11102-$A111FF	Reserved
    static uint16_t z80Reset;			            // $A11200-$A11201	Z80 reset
    static uint32_t TMSS;			                // $A14000-$A14003	TMSS register
                                                    // $A14004-$BFFFFF	Reserved
    static uint16_t VDPData;					    // $C00000-$C00001	VDP data
#define VDPDataMirror VDPData                       // $C00002-$C00003	VDP data (mirror)
    static uint16_t VDPControl;				        // $C00004-$C00005	VDP control
#define VDPControlMirror VDPControl                 // $C00006-$C00007	VDP control (mirror)
    static uint16_t VDPHVCounter;                   // $C00008-$C00009	VDP HV counter
                                                    // $C0000A-$C00010	Reserved
    static uint8_t PSGOutput;                       // $C00011	PSG output
                                                    // $C00012-$FEFFFF	Reserved
    static Ram* ram;                                // $FF0000-$FFFFFF	68000 RAM

    void init();
};
