//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_ERROREXCEPTION_H
#define M68KSIMULATOR_ERROREXCEPTION_H


#include <stdexcept>

class ErrorException : std::runtime_error {
public:
    ErrorException(const std::string &__arg);

};


#endif //M68KSIMULATOR_ERROREXCEPTION_H
