//
// Created by ggonz on 3/10/2017.
//

#pragma once


#include <stdexcept>

/**
 * 6.3.10 Address Error
    An address error exception occurs when the processor attempts to access a word or longword
    operand or an instruction at an odd address.
 */

class AddressException : std::runtime_error {
public:
    AddressException(const std::string &__arg);

};
