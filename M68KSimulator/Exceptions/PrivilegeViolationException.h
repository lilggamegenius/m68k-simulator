//
// Created by ggonz on 3/10/2017.
//

#ifndef M68KSIMULATOR_PRIVILEGEVIOLATIONEXCEPTION_H
#define M68KSIMULATOR_PRIVILEGEVIOLATIONEXCEPTION_H


#include <stdexcept>

class PrivilegeViolationException : std::runtime_error {
public:
    PrivilegeViolationException(const std::string &__arg);

};


#endif //M68KSIMULATOR_PRIVILEGEVIOLATIONEXCEPTION_H
