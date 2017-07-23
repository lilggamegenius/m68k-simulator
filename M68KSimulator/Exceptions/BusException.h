//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_BUSEXCEPTION_H
#define M68KSIMULATOR_BUSEXCEPTION_H

#include <stdexcept>

/**
 * 6.3.9 Bus Error
    A bus error exception occurs when the external logic requests that a bus error be
    processed by an exception.
 */

class BusException : std::runtime_error {
public:
    BusException(const std::string &__arg);

};


#endif //M68KSIMULATOR_BUSEXCEPTION_H
