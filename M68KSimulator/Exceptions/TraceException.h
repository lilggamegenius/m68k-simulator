//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_TRACEEXCEPTION_H
#define M68KSIMULATOR_TRACEEXCEPTION_H


#include <stdexcept>

class TraceException : std::runtime_error {
public:
    TraceException(const std::string &__arg);

};


#endif //M68KSIMULATOR_TRACEEXCEPTION_H
