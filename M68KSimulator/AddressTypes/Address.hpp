//
// Created by lil-g on 10/18/17.
//

class Address;

#pragma once

#include "../Exceptions/AddressException.h"
#include "../Registers.hpp"

class Address{
public:
	M68kAddr addr;
	Size size = Size::Byte;

	virtual Address *operator=(uint8_t value)=0;

	virtual Address *operator=(uint16_t value)=0;

	virtual Address *operator=(uint32_t value)=0;

	virtual Address *operator=(int8_t value)=0;

	virtual Address *operator=(int16_t value)=0;

	virtual Address *operator=(int32_t value)=0;

	virtual Address *operator=(Address *address)=0;

	virtual Address *operator=(DataRegister dRegister)=0;

	virtual Address *operator=(AddressRegister aRegister)=0;

	virtual M68kAddr operator&()=0;

	virtual Address *operator*()=0;

	virtual operator bool() = 0;

	virtual operator uint8_t() = 0;

	virtual operator uint16_t() = 0;

	virtual operator uint32_t() = 0;

	virtual operator int8_t() = 0;

	virtual operator int16_t() = 0;

	virtual operator int32_t() = 0;

	virtual void checkForOddAddress();

};
