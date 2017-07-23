//
// Created by ggonz on 3/10/2017.
//

#include "IllegalInstructionException.h"

IllegalInstructionException::IllegalInstructionException(const std::string &__arg) : runtime_error(__arg) {}
