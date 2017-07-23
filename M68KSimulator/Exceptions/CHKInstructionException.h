//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_CHKINSTRUCTIONEXCEPTION_H
#define M68KSIMULATOR_CHKINSTRUCTIONEXCEPTION_H


#include <stdexcept>

class CHKInstructionException : std::runtime_error {
public:
    CHKInstructionException(const std::string &__arg);

};


#endif //M68KSIMULATOR_CHKINSTRUCTIONEXCEPTION_H
