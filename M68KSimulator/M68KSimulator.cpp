//
// Created by ggonz on 3/9/2017.
//
#include <iostream>
#include <cstring>
#include "M68KSimulator.hpp"

M68KSimulator::M68KSimulator(){
	init();
}

EXPORT void M68KSimulator::init(){
	err = uc_open(UC_ARCH_M68K, UC_MODE_BIG_ENDIAN, &uc);
	if(err){
		std::cerr << "Failed on uc_open() with error returned: " << err << ": " << uc_strerror(err) << std::endl;
		return;
	}

	const uint64_t size = sizeof(addressSpace);

	err = uc_mem_map_ptr(uc, 0, size, UC_PROT_ALL, &addressSpace);
	if(err){
		std::cerr << "Failed to map address space: " << err << ": " << uc_strerror(err) << std::endl;
		return;
	}
}

bool M68KSimulator::unload(){
	//delete addressSpace;
	uc_close(uc);
	return false;
}

M68KSimulator::~M68KSimulator(){
	unload();
}

EXPORT int M68KSimulator::run(std::string path){
	std::ifstream file;
	file.open(path, std::ios::in | std::ios::binary);
	return run(std::move(file));
}

EXPORT int M68KSimulator::run(char *path){
	std::ifstream file(path);
	file.open(path, std::ios::in | std::ios::binary);
	return run(std::move(file));
}

/*EXPORT int M68KSimulator::run(FILE *file){
	std::filebuf filebuf(file);
	return -1;
}*/

EXPORT int M68KSimulator::run(std::ifstream file){
	setRom(std::move(file));
	return 0;
}

void M68KSimulator::setRom(std::ifstream file){
	init();
	if(file){   // Opened
		// get length of file:
		file.seekg(0, std::ifstream::end);
		long length = file.tellg();
		file.seekg(0, std::ifstream::beg);
		if(length > romSize) throw std::overflow_error("File is larger than max rom size");
		file.read(reinterpret_cast<char *>(addressSpace.rom.s8), length);
		if(file){
			std::cout << "Filled buffer" << std::endl;
		} else{
			std::cout << "File read failed, read \"" << file.gcount() << "\" bytes" << std::endl;
            fill();
		}
	} else{     // Error
		std::cout << "Error opening file" << std::endl;
	}
}


void M68KSimulator::fill(){
	memset(addressSpace.rom.u32, 0, sizeof(addressSpace.rom.u32));
}

EXPORT registers M68KSimulator::getDataRegister(DataRegister dataRegister){
	registers result;
	uc_reg_read(uc, UC_M68K_REG_D0 + dataRegister, &result);
	return result;
}

EXPORT registers M68KSimulator::getAddressRegister(AddressRegister addressRegister){
	registers result;
	int register_ = UC_M68K_REG_A0 + addressRegister;
	if(addressRegister == usp) register_ = UC_M68K_REG_INVALID;
	uc_reg_read(uc, register_, &result);
	return result;
}

EXPORT uint8_t M68KSimulator::getAddress8(uint32_t address){
	uint8_t result;
	uc_mem_read(uc, address, &result, sizeof(result));
	return result;
}

EXPORT uint16_t M68KSimulator::getAddress16(uint32_t address){
	uint16_t result;
	uc_mem_read(uc, address, &result, sizeof(result));
	return result;
}

EXPORT uint32_t M68KSimulator::getAddress32(uint32_t address){
	uint32_t result;
	uc_mem_read(uc, address, &result, sizeof(result));
	return result;
}

CEXPORT void init(M68KSimulator* sim){
	sim->init();
}
CEXPORT int run(M68KSimulator* sim, char path[]){
	return sim->run(path);
}
CEXPORT bool unload(M68KSimulator* sim){
	return sim->unload();
}
CEXPORT registers getDataRegister(M68KSimulator* sim, DataRegister dataRegister){
	return sim->getDataRegister(dataRegister);
}
CEXPORT registers getAddressRegister(M68KSimulator* sim, AddressRegister addressRegister){
	return sim->getAddressRegister(addressRegister);
}
CEXPORT uint8_t getAddress8(M68KSimulator* sim, uint32_t address){
	return sim->getAddress8(address);
}
CEXPORT uint16_t getAddress16(M68KSimulator* sim, uint32_t address){
	return sim->getAddress16(address);
}
CEXPORT uint32_t getAddress32(M68KSimulator* sim, uint32_t address){
	return sim->getAddress32(address);
}

/*
 * All supported instructions for the M68000
 * ABCD             - Add Decimal with Extend
 * ADD              - Add
 * ADDA             - Address
 * ADDI             - Add Immediate
 * ADDQ             - Add Quick
 * ADDX             - Add with Extend
 * AND              - Logical AND
 * ANDI             - Logical AND Immediate
 * ANDI to CCR      - AND Immediate to Condition Code Register
 * ANDI to SR 1     - AND Immediate to Status Register
 * ASL, ASR         - Arithmetic Shift Left and Right
 * Bcc              - Branch Conditionally
 * BCHG             - Test Bit and Change
 * BCLR             - Test Bit and Clear
 * BRA              - Branch
 * BSET             - Test Bit and Set
 * BSR              - Branch to Subroutine
 * BTST             - Test Bit
 * CHK              - Check Register Against Bound
 * CLR              - Clear
 * CMP              - Compare
 * CMPA             - Compare Address
 * CMPI             - Compare Immediate
 * CMPM             - Compare Memory to Memory
 * DBcc             - Test Condition, Decrement and Branch
 * DIVS             - Signed Divide
 * DIVU             - Unsigned Divide
 * EOR              - Logical Exclusive-OR
 * EORI             - Logical Exclusive-OR Immediate
 * EORI to CCR      - Exclusive-OR Immediate to Condition Code Register
 * EORI to SR 1     - Exclusive-OR Immediate to Status Register
 * EXG              - Exchange Registers
 * EXT              - Sign Extend
 * LLEGAL           - Take Illegal Instruction Trap
 * JMP              - Jump
 * JSR              - Jump to Subroutine
 * LEA              - Load Effective Address
 * LINK             - Link and Allocate
 * LSL,LSR          - Logical Shift Left and Right
 * MOVE             - Move
 * MOVEA            - Move Address
 * MOVE to CCR      - Move to Condition Code Register
 * MOVE from SR 1   - Move from Status Register
 * MOVE to SR 1     - Move to Status Register
 * MOVE USP 1       - Move User Stack Pointer
 * MOVEM            - Move Multiple Registers
 * MOVEP            - Move Peripheral
 * MOVEQ            - Move Quick
 * MULS             - Signed Multiply
 * MULU             - Unsigned Multiply
 * NBCD             - Negate Decimal with Extend
 * NEG              - Negate
 * NEGX             - Negate with Extend
 * NOP              - No Operation
 * NOT              - Logical Complement
 * OR               - Logical Inclusive-OR
 * ORI              - Logical Inclusive-OR Immediate
 * ORI to CCR       - Inclusive-OR Immediate to Condition Code Register
 * ORI to SR 1      - Inclusive-OR Immediate to Status Register
 * PEA              - Push Effective Address
 * RESET 1          - Reset External Devices
 * ROL,ROR          - Rotate Left and Right
 * ROXL, ROXR       - Rotate with Extend Left and Right
 * RTE 1            - Return from Exception
 * RTR              - Return and Restore
 * RTS              - Return from Subroutine
 * SBCD             - Subtract Decimal with Extend
 * Scc              - Set Conditionally
 * STOP 1           - Stop
 * SUB              - Subtract
 * SUBA             - Subtract Address
 * SUBI             - Subtract Immediate
 * SUBQ             - Subtract Quick
 * SUBX             - Subtract with Extend
 * SWAP             - Swap Register Words
 * TAS              - Test Operand and Set
 * TRAP             - Trap
 * TRAPV            - Trap on Overflow
 * TST              - Test Operand
 * UNLK             - Unlink
 */