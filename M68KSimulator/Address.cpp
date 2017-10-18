//
// Created by ggonz on 3/14/2017.
//

#include "Address.h"

Address::Address(M68kAddr address, Size size) {
    addr = address;
    this->size = size;
}

Address &Address::operator=(uint8_t value) {
    Ram::memory->u8[addr / sizeof(value)] = value;
    return *this;
}

Address &Address::operator=(uint16_t value) {
    Ram::memory->u16[addr / sizeof(value)] = value;
    return *this;
}

Address &Address::operator=(uint32_t value) {
    Ram::memory->u32[addr / sizeof(value)] = value;
    return *this;
}

Address &Address::operator=(int8_t value) {
    Ram::memory->s8[addr / sizeof(value)] = value;
    return *this;
}

Address &Address::operator=(int16_t value) {
    Ram::memory->s16[addr / sizeof(value)] = value;
    return *this;
}

Address &Address::operator=(int32_t value) {
    Ram::memory->s32[addr / sizeof(value)] = value;
    return *this;
}

Address &Address::operator=(Address address) {
	switch(address.size){
	case Size::Byte:(*this) = (uint8_t) address;
		break;
	case Size::Word:(*this) = (uint16_t) address;
		break;
	case Size::Longword:(*this) = (uint32_t) address;
    }
    return *this;
}

Address &Address::operator=(DataRegister dRegister) {
	switch(size){
	case Size::Byte:(*this) = dataRegisters[dRegister].u8[0];
		break;
	case Size::Word:(*this) = dataRegisters[dRegister].u16[0];
		break;
	case Size::Longword:(*this) = dataRegisters[dRegister].u32;
    }
    return *this;
}

Address &Address::operator=(AddressRegister aRegister) {
	switch(size){
	case Size::Byte:(*this) = addressRegisters[aRegister]->u8[0];
		break;
	case Size::Word:(*this) = addressRegisters[aRegister]->u16[0];
		break;
	case Size::Longword:(*this) = addressRegisters[aRegister]->u32;
    }
    return *this;
}

Address::operator bool() {
	switch(size){
	case Size::Byte:return (bool) Ram::memory->u8[addr];
	case Size::Word:return (bool) Ram::memory->u16[addr / 2];
	case Size::Longword:return (bool) Ram::memory->u32[addr / 4];
	default:return false;
    }
}

Address::operator uint8_t() {
    return Ram::memory->u8[addr];
}

Address::operator uint16_t() {
    return Ram::memory->u16[addr / 2];
}

Address::operator uint32_t() {
    return Ram::memory->u32[addr / 4];
}

Address::operator int8_t() {
    return Ram::memory->s8[addr];
}

Address::operator int16_t() {
    return Ram::memory->s16[addr / 2];
}

Address::operator int32_t() {
    return Ram::memory->s32[addr / 4];
}

M68kAddr Address::operator&() {
    return addr;
}

Address Address::operator*() {
    return Address(Ram::memory->u32[addr / 4]);
}
