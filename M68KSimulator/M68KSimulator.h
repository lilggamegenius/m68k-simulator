//
// Created by ggonz on 3/9/2017.
//

#ifndef M68KSIMULATOR_M68KSIMULATOR_H
#define M68KSIMULATOR_M68KSIMULATOR_H

class AddressSpace;
class Rom;
class Address;

#if defined(_MSC_VER)
//  Microsoft
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC or CLANG
#define EXPORT __attribute__((visibility("default")))
#define IMPORT
#else
//  do nothing and hope for the best?
#define EXPORT
#define IMPORT
#pragma warning Unknown dynamic link import/export semantics.
#endif

#define CEXPORT extern "C" EXPORT

#include "AddressSpace.h"

class M68KSimulator {
public:
    void init();
};


#endif //M68KSIMULATOR_M68KSIMULATOR_H
