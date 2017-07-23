//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_ZERODIVIDEEXCEPTION_H
#define M68KSIMULATOR_ZERODIVIDEEXCEPTION_H


#include <stdexcept>

class ZeroDivideException : std::runtime_error {
public:
    ZeroDivideException(const std::string &__arg);

};


#endif //M68KSIMULATOR_ZERODIVIDEEXCEPTION_H
