//
// Created by ggonz on 3/14/2017.
//

#ifndef M68KSIMULATOR_ADDRESS_H
#define M68KSIMULATOR_ADDRESS_H


#include "AddressSpace.h"

class Address {
    M68kAddr addr;
    Size size = Size::Byte;
public:
    Address(M68kAddr address, Size size = Size::Byte);

    Address &operator=(uint8_t value);

    Address &operator=(uint16_t value);

    Address &operator=(uint32_t value);

    Address &operator=(int8_t value);

    Address &operator=(int16_t value);

    Address &operator=(int32_t value);

    Address &operator=(Address address);

    Address &operator=(DataRegister dRegister);

    Address &operator=(AddressRegister aRegister);

    M68kAddr operator&();

    Address operator*();

    operator bool();

    operator uint8_t();

    operator uint16_t();

    operator uint32_t();

    operator int8_t();

    operator int16_t();

    operator int32_t();

};


#endif //M68KSIMULATOR_ADDRESS_H
