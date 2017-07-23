//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_ADDRESSEXCEPTION_H
#define M68KSIMULATOR_ADDRESSEXCEPTION_H


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


#endif //M68KSIMULATOR_ADDRESSEXCEPTION_H
