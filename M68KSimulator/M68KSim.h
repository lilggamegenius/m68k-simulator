//
// Created by lil-g on 1/19/18.
//

#pragma once

#if defined(_MSC_VER)
//  Microsoft
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC or CLANG
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
//  do nothing and hope for the best?
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#define CEXPORT extern "C" EXPORT

/*CEXPORT void init(M68KSim* sim);
CEXPORT int run(M68KSim* sim, char path[]);
CEXPORT bool unload(M68KSim* sim);
CEXPORT registers getDataRegister(M68KSim* sim, DataRegister dataRegister);
CEXPORT registers getAddressRegister(M68KSim* sim, AddressRegister addressRegister);
CEXPORT uint8_t getAddress8(M68KSim* sim, uint32_t address);
CEXPORT uint16_t getAddress16(M68KSim* sim, uint32_t address);
CEXPORT uint32_t getAddress32(M68KSim* sim, uint32_t address);*/

