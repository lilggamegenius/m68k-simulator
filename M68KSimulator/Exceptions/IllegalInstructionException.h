//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_ILLEGALINSTRUCTIONEXCEPTION_H
#define M68KSIMULATOR_ILLEGALINSTRUCTIONEXCEPTION_H


#include <stdexcept>

class IllegalInstructionException : std::runtime_error {
public:
    IllegalInstructionException(const std::string &__arg);

};


#endif //M68KSIMULATOR_ILLEGALINSTRUCTIONEXCEPTION_H
