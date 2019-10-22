//
// Created by ggonz on 3/9/2017.
//
#pragma once

#include <fstream>
#include <unicorn/unicorn.h>
#include "AddressSpace.hpp"
#include "M68KSim.h"

struct M68KSim;

class M68KSimulator {
public:
	AddressSpace* addressSpace;

	EXPORT M68KSimulator();

	EXPORT ~M68KSimulator();

	EXPORT void init();

	EXPORT int run(std::string path);

	EXPORT int run(char path[]);

	//EXPORT int run(FILE *file);

	EXPORT int run(std::ifstream file);

	EXPORT bool unload();

	EXPORT void fill();

	EXPORT registers getDataRegister(DataRegister dataRegister);

	EXPORT registers getAddressRegister(AddressRegister addressRegister);

	EXPORT uint8_t getAddress8(uint32_t address);
	EXPORT uint16_t getAddress16(uint32_t address);
	EXPORT uint32_t getAddress32(uint32_t address);

private:
	uc_engine *uc;
	uc_err err;

	void setRom(std::ifstream);
};
