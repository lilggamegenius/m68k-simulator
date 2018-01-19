//
// Created by lil-g on 10/18/17.
//

class RamAddress;

#pragma once

#include "Address.hpp"

class RamAddress : public Address{

public:

	RamAddress(M68kAddr address, Size size = Size::Byte);

	Address *operator=(uint8_t value);

	Address *operator=(uint16_t value);

	Address *operator=(uint32_t value);

	Address *operator=(int8_t value);

	Address *operator=(int16_t value);

	Address *operator=(int32_t value);

	Address *operator=(Address *address);

	Address *operator=(DataRegister dRegister);

	Address *operator=(AddressRegister aRegister);

	M68kAddr operator&();

	Address *operator*();

	operator bool();

	operator uint8_t();

	operator uint16_t();

	operator uint32_t();

	operator int8_t();

	operator int16_t();

	operator int32_t();

};