//
// Created by ggonz on 3/10/2017.
//

#include "PrivilegeViolationException.h"

PrivilegeViolationException::PrivilegeViolationException(const std::string &__arg) : runtime_error(__arg) {}
