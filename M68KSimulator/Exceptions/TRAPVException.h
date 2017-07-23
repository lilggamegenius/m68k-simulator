//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_TRAPVEXCEPTION_H
#define M68KSIMULATOR_TRAPVEXCEPTION_H


#include <stdexcept>

class TRAPVException : std::runtime_error {
public:
    TRAPVException(const std::string &__arg);

};


#endif //M68KSIMULATOR_TRAPVEXCEPTION_H
