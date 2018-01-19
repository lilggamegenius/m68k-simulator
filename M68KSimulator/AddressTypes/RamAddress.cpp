//
// Created by ggonz on 3/14/2017.
//

#include "RamAddress.hpp"
#include "../Ram.hpp"

#define startOfRam 0xFF0000

RamAddress::RamAddress(M68kAddr address, Size size){
	addr = address - startOfRam;
	this->size = size;
}

Address *RamAddress::operator=(uint8_t value){
	Ram::memory->u8[addr] = value;
	return this;
}

Address *RamAddress::operator=(uint16_t value){
	checkForOddAddress();
	Ram::memory->u16[addr / 2] = value;
	return this;
}

Address *RamAddress::operator=(uint32_t value){
	checkForOddAddress();
	Ram::memory->u32[addr / 4] = value;
	return this;
}

Address *RamAddress::operator=(int8_t value){
	Ram::memory->s8[addr] = value;
	return this;
}

Address *RamAddress::operator=(int16_t value){
	checkForOddAddress();
	Ram::memory->s16[addr / 2] = value;
	return this;
}

Address *RamAddress::operator=(int32_t value){
	checkForOddAddress();
	Ram::memory->s32[addr / 4] = value;
	return this;
}

Address *RamAddress::operator=(Address *address){
	switch(address->size){
	case Size::Byte: *this = (uint8_t) *address;
		break;
	case Size::Word: *this = (uint16_t) *address;
		break;
	case Size::Longword: *this = (uint32_t) *address;
	}
	return this;
}

Address *RamAddress::operator=(DataRegister dRegister){
	switch(size){
	case Size::Byte: *this = dataRegisters[dRegister].u8[0];
		break;
	case Size::Word: *this = dataRegisters[dRegister].u16[0];
		break;
	case Size::Longword: *this = dataRegisters[dRegister].u32;
	}
	return this;
}

Address *RamAddress::operator=(AddressRegister aRegister){
	switch(size){
	case Size::Byte: *this = addressRegisters[aRegister].u8[0];
		break;
	case Size::Word: *this = addressRegisters[aRegister].u16[0];
		break;
	case Size::Longword: *this = addressRegisters[aRegister].u32;
	}
	return this;
}

M68kAddr RamAddress::operator&(){
	return addr + startOfRam;
}

Address *RamAddress::operator*(){
	return new RamAddress(Ram::memory->u32[addr / 4]);
}

RamAddress::operator bool(){
	switch(size){
	case Size::Byte: return (bool) Ram::memory->u8[addr];
	case Size::Word: return (bool) Ram::memory->u16[addr / 2];
	case Size::Longword: return (bool) Ram::memory->u32[addr / 4];
	default: return false;
	}
}

RamAddress::operator uint8_t(){
	return Ram::memory->u8[addr];
}

RamAddress::operator uint16_t(){
	return Ram::memory->u16[addr / 2];
}

RamAddress::operator uint32_t(){
	return Ram::memory->u32[addr / 4];
}

RamAddress::operator int8_t(){
	return Ram::memory->s8[addr];
}

RamAddress::operator int16_t(){
	return Ram::memory->s16[addr / 2];
}

RamAddress::operator int32_t(){
	return Ram::memory->s32[addr / 4];
}
