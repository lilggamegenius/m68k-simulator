//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_LINE1010EMULATOREXCEPTION_H
#define M68KSIMULATOR_LINE1010EMULATOREXCEPTION_H


#include <stdexcept>

class Line1010EmulatorException : std::runtime_error {
public:
    Line1010EmulatorException(const std::string &__arg);

};


#endif //M68KSIMULATOR_LINE1010EMULATOREXCEPTION_H
